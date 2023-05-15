#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QRandomGenerator>

constexpr size_t N = 1000; //Размер данных
constexpr double treshold = 0.002; //Порог тренда отношения скоростей

void generateData(QVector<double>& data, double grow_coefficient) { //Генерация данных с шумом и трендом
    QVector<double> trend(N, 0);
    double delta{0};
    for(auto& i:trend) {
        i += delta;
        delta += grow_coefficient/static_cast<double>(N);
    }
    std::mt19937 engine{};
    std::normal_distribution<> distr(0,3);

    for(auto& i:data) {
         i += distr(engine);
    }
    std::transform(std::begin(data), std::end(data), std::begin(trend), std::begin(data), std::plus<double>());
}

double leastSquares(const QVector<double>& y, const QVector<double>& x, QVector<double>& y_fit_o) { //Метод наименьших квадратов
    size_t n = x.size();
    double x_sum{0}, y_sum{0}, x2_sum{0}, xy_sum{0};
    for (auto i = 0; i < y.size(); ++i)
    {
        x_sum+=x[i];
        y_sum+=y[i];
        x2_sum+=std::pow(x[i],2);
        xy_sum+=x[i]*y[i];
    }
    double a=(n*xy_sum-x_sum*y_sum)/(n*x2_sum-x_sum*x_sum);
    double b=(x2_sum*y_sum-x_sum*xy_sum)/(x2_sum*n-x_sum*x_sum);
    for (auto i = 0; i < y_fit_o.size(); i++)
        y_fit_o[i]=a*x[i]+b;
    return a;
}

bool estimateDataTrend(const QVector<double>& data) {
    QVector<double> y_fit(N, 0);
    QVector<double> t(N);
    std::iota(std::begin(t), std::end(t), 0);
    double y = leastSquares(data, t, y_fit);
    if(std::abs(y) > treshold) return true; //Наличие тренда данных
    else return false; //Отсутствие тренда данных
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCustomPlot* plot1 = ui->plot;
    QCustomPlot* plot2 = ui->plot_2;
    initPlot(plot1);
    initPlot(plot2);
    setFixedHeight(900);
    setFixedWidth(1600);
    ui->plot->addGraph();
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(QColor(80, 200, 80), 3));
    ui->plot->graph(1)->setPen(QPen(QColor(17, 96, 242), 3));

    ui->plot_2->addGraph();
    ui->plot_2->addGraph();
    ui->plot_2->graph(0)->setPen(QPen(QColor(80, 200, 80), 3));
    ui->plot_2->graph(1)->setPen(QPen(QColor(17, 96, 242), 3));

    QVector<double> data(N, 0);
    QVector<double> t(N);
    std::iota(std::begin(t), std::end(t), 0);

    generateData(data, 5);
    QVector<double> y_fit(N, 0);
    leastSquares(data, t, y_fit);
    ui->plot->graph(0)->setData(t,data);
    ui->plot->graph(1)->setData(t,y_fit);

    std::string output;
    if(estimateDataTrend(data)) output = "Наличие тренда данных";
    else output = "Отсутствие тренда данных";
    std::cout << output << std::endl;

    data.fill(0);
    y_fit.fill(0);

    generateData(data, 1);
    leastSquares(data, t, y_fit);
    ui->plot_2->graph(0)->setData(t,data);
    ui->plot_2->graph(1)->setData(t,y_fit);
    if(estimateDataTrend(data)) output = "Наличие тренда данных";
    else output = "Отсутствие тренда данных";
    std::cout << output << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPlot(QCustomPlot* plot)
{
    plot->xAxis->setBasePen(QPen(Qt::white, 1));
    plot->yAxis->setBasePen(QPen(Qt::white, 1));
    plot->xAxis->setTickPen(QPen(Qt::white, 1));
    plot->yAxis->setTickPen(QPen(Qt::white, 1));
    plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridVisible(true);
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    plot->yAxis->setRange(-10,10);
    plot->xAxis->setRange(0,N);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    plot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    plot->axisRect()->setBackground(axisRectGradient);
}

