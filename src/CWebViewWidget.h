#ifndef CWEBVIEWWIDGET_H
#define CWEBVIEWWIDGET_H

#include <QWidget>
#include "Browser_Widgets/webview.h"
#include "Browser_Widgets/webpage.h"
#include <QWebEngineFullScreenRequest>

class CWebViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CWebViewWidget(QWidget *parent = nullptr);
    void        setWebUrl(QString strUrl);
    QString     getWebUrl(){return m_strUrl;}
    void        setZoomRate(float rate);

private:
    WebView     *m_pWebView;
    WebPage     *m_pWebPage;
    QString     m_strUrl;

signals:

private slots:
    void    acceptFullScreen(QWebEngineFullScreenRequest request);

};

#endif // CWEBVIEWWIDGET_H
