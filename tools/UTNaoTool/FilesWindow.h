#ifndef FILES_WINDOW_H
#define FILES_WINDOW_H

#include <QDir>
#include <QFileSystemWatcher>
#include <QProcess>
#include <QCheckBox>
#include <QDateTime>
#include <QPalette>
#include <common/RobotConfig.h>

#include <tool/ProcessExecutor.h>
#include <tool/ConfigWindow.h>
#include "ui_FilesWindow.h"

class FilesWindow : public ConfigWindow, public Ui_UTFilesWindow {
 Q_OBJECT
  private:
   ProcessExecutor executor_;
   ProcessExecutor::Callback getStatusCallback(QString message);

  public:
    FilesWindow(QMainWindow* pa);
    QDir* luaDir;
    QString basePath;
    QString logPath;
    QString dataPath;
    QFileSystemWatcher* luaWatch;
    QCheckBox* files;
    QMainWindow* parent;
    int numFiles;

    QProcessEnvironment environment;
    bool isRobotTimeSet;
    QDateTime prevTime;
    bool pingStatus;
		QTimer *statusTimer;
    void naoqiCommand(QString c);

    bool sendCopyRobotCommand(QString command, bool verbose = true);

  signals:
    void statusUpdated(QString status);
    void robotStatusUpdated(bool alive);
    
  public slots:

    void loadBehaviors();
    void runBehavior();
    
    void loadConfig(const ToolConfig& config);
    void saveConfig(ToolConfig& config);

    void setRobotTime();
    void updateRobotStatus(bool alive);
    void setInitial();
    void setReady();
    void setSet();
    void setPlaying();
    void setTesting();
    void setPenalised();
    void setFinished();
    void setBottomCameraBehavior();
    void setTopCameraBehavior();
    void setTestOdometry();

    void resetTopCamera();
    void resetBottomCamera();

    void sendLua(bool verbose = true);
    void verifyLua(bool verbose = true);

    void sendPython(bool verbose = true);
    void verifyPython(bool verbose = true);

    void sendBinary(bool verbose = true);
    void verifyBinary(bool verbose = true);

    void sendAll(bool verbose = true);
    void verifyAll(bool verbose = true);

    void sendEverything(bool verbose = true);
    void verifyEverything(bool verbose = true);

    void sendVision(bool verbose = true);
    void verifyVision(bool verbose = true);

    void sendMotion(bool verbose = true);
    void verifyMotion(bool verbose = true);

    void sendInterface(bool verbose = true);
    void verifyInterface(bool verbose = true);

    void sendMotionFiles(bool verbose = true);
    void verifyMotionFiles(bool verbose = true);

    void sendConfigFiles(bool verbose = true);
    void verifyConfigFiles(bool verbose = true);

    void sendColorTable(bool verbose = true);
    void verifyColorTable(bool verbose = true);
    
    void sendWireless(bool verbose = true);
    //void verifyWireless(bool verbose = true);

    void sendAutoloadFile(bool verbose = true);
    void verifyAutoloadFile(bool verbose = true);

    void sendSimpleConfig(bool verbose = true);
    void verifySimpleConfig(bool verbose = true);

    void restartNaoQi();

    void getLogs();
    void removeLogs();
    void checkStatus(bool repeat = true);
    void sendMp3Files();
    void sendFile(QString from, QString to, QString name);
    void changeLocationIndex(int index);

    void stopNaoqi();
    void startNaoqi();


    void enableButtons(bool b);
    void locationChanged(int index);
    void setCurrentLocation(QString ip);

};

#endif

