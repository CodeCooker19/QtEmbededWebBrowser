#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QIcon>
#include <QWebEngineView>
//#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include "webpage.h"

//class WebPage;

class WebView : public QWebEngineView
{
    Q_OBJECT

public:
    WebView(QWidget *parent = nullptr);
    void setPage(WebPage *page);

    int loadProgress() const;
    bool isWebActionEnabled(QWebEnginePage::WebAction webAction) const;
    QIcon favIcon() const;

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

signals:
    void webActionEnabledChanged(QWebEnginePage::WebAction webAction, bool enabled);
    void favIconChanged(const QIcon &icon);
    void devToolsRequested(QWebEnginePage *source);
    void sendImage(QPixmap pixmap);

private slots:
    void onImage();

private:
    void createWebActionTrigger(QWebEnginePage *page, QWebEnginePage::WebAction);

private:
    int m_loadProgress;
};

#endif
