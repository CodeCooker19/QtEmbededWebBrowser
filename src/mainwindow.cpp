#include "mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QHBoxLayout *pMainLayout;
    pMainLayout = new QHBoxLayout(this);
    m_pWebViewWidget = new CWebViewWidget(this);

    m_pWebViewWidget->setFixedSize(400, 300);
    pMainLayout->addWidget(m_pWebViewWidget);
    setLayout(pMainLayout);

    m_pWebViewWidget->setWebUrl("https://www.yahoo.com");

}

MainWindow::~MainWindow()
{

}
