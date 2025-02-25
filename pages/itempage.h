#ifndef ITEMPAGE_H
#define ITEMPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <DSuggestButton>
#include <DWarningButton>
#include <DProgressBar>
#include <DSpinner>
#include "backend/appstreamhelper.h"

DWIDGET_USE_NAMESPACE

class ItemPage : public QWidget
{
    Q_OBJECT

public:
    ItemPage(QString app, bool snap);
    enum Status {
        Installed,
        NotInstalled,
        Installing,
        Launchable
    };
    void setInstallButton(QString packageId, Status type, QString param = nullptr);
    void setData(AppStreamHelper::appData data);
private:
    QVBoxLayout *layout;
    DWarningButton *removeBtn;
    DSuggestButton *installBtn;
    DProgressBar *progressBar;
    DSpinner *spinner = new DSpinner;
    bool isSnap;
    QString m_app;
};

#endif // ITEMPAGE_H