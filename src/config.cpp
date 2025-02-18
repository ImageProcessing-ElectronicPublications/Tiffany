//
// Global configuration
//
#include <QSettings>
#include "config.h"

namespace Config
{
    int dropperThreshold;
    int floodThreshold;
    double deskewAngle;
    int despeckleArea;
    int brushSize;
    int blurRadius;
    int kernelSize;
    QFont textFont;

    // Load settings file
    void LoadConfig()
    {
        QSettings settings;

        dropperThreshold = settings.value("dropperThreshold", 20).toInt();
        floodThreshold = settings.value("floodThreshold", 50).toInt();
        deskewAngle = settings.value("deskewAngle", 0.0).toDouble();
        despeckleArea = settings.value("despeckleArea", 20).toInt();
        brushSize = settings.value("brushSize", 1).toInt();
        if (brushSize >= 12)
            brushSize = 12;
        else if (brushSize >= 8)
            brushSize = 8;
        else if (brushSize >= 4)
            brushSize = 4;
        else
            brushSize = 1;
        blurRadius = settings.value("blurRadius", 5).toInt();
        if (blurRadius % 2 != 1)
            blurRadius++;
        kernelSize = settings.value("kernelSize", 23).toInt();
        if (kernelSize % 2 != 1)
            kernelSize++;
        QString font = settings.value("font", "Courier New,20,-1,5,50,0,0,0,0,0").toString();
        textFont.fromString(font);
    }

    // Save settings file
    void SaveConfig()
    {
        QSettings settings;
        settings.setValue("dropperThreshold", dropperThreshold);
        settings.setValue("floodThreshold", floodThreshold);
        settings.setValue("deskewAngle", deskewAngle);
        settings.setValue("despeckleArea", despeckleArea);
        settings.setValue("brushSize", brushSize);
        settings.setValue("blurRadius", blurRadius);
        settings.setValue("kernelSize", kernelSize);
        settings.setValue("font", textFont.toString());
    }
}
