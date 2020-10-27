#include "CWebViewWidget.h"
#include <QWebEngineProfile>
#include <QLayout>
#include <QException>
#include <QThread>
#include <QWebEngineSettings>

CWebViewWidget::CWebViewWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *pMainLayout;

    pMainLayout = new QHBoxLayout(this);

    for(int i=0; i< 100; i++){
        try {
            m_pWebView = new WebView (this);

        } catch (...) {
            qDebug()<<"----------------"<<i;
            continue;
        }
        break;
    }

    for(int i=0; i< 100; i++){
        try {
            m_pWebPage = new WebPage(new QWebEngineProfile, this);

        } catch (...) {
            qDebug()<<"----------------"<<i;
            continue;
        }
        break;
    }

    m_pWebView->setPage(m_pWebPage);
//    m_pWebView->setUrl(QUrl("https://www.google.com"));
//    m_pWebView->setFixedSize(200, 120);

    pMainLayout->setMargin(0);
    pMainLayout->setSpacing(0);
    pMainLayout->addWidget(m_pWebView);
    setLayout(pMainLayout);

    m_pWebView->showFullScreen();
    m_pWebView->settings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled,true);
    m_pWebView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);
    m_pWebView->settings()->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows,true);
    connect(m_pWebView->page(),&QWebEnginePage::fullScreenRequested,this,&CWebViewWidget::acceptFullScreen);
}

void CWebViewWidget::setWebUrl(QString strUrl){
    m_strUrl = strUrl;
    m_pWebView->setUrl(QUrl(m_strUrl));
//    m_pWebView->setZoomFactor(0.25);
//    m_pWebView->setStyleSheet("overflow:hidden");
    m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
}

void CWebViewWidget::setZoomRate(float rate){
    m_pWebView->setZoomFactor(rate);
}

//private slots:
void CWebViewWidget::acceptFullScreen(QWebEngineFullScreenRequest request){
    if(request.toggleOn()){
        request.accept();

        m_pWebView->showFullScreen();
    }
    else{
        request.accept();
    }
}
