#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWebEnginePage>
//#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QWebEngineRegisterProtocolHandlerRequest>

class WebPage : public QWebEnginePage
{
    Q_OBJECT

public:
    WebPage(QWebEngineProfile *profile, QObject *parent = nullptr);

protected:
    bool certificateError(const QWebEngineCertificateError &error) override;

private slots:
    void handleFeaturePermissionRequested(const QUrl &securityOrigin, Feature feature);
    void handleRegisterProtocolHandlerRequested(QWebEngineRegisterProtocolHandlerRequest request);
#if !defined(QT_NO_SSL) || QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    void handleSelectClientCertificate(QWebEngineClientCertificateSelection clientCertSelection);
#endif
};

#endif // WEBPAGE_H
