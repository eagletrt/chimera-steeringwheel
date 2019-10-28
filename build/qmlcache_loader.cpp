#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,1,0,0,0,1,0,0,0,
8,0,2,0,0,0,28,0,0,0,2,0,0,3,22,0,
0,0,0,0,1,0,0,0,0,0,0,2,144,0,0,0,
0,0,1,0,0,0,0,0,0,0,248,0,0,0,0,0,
1,0,0,0,0,0,0,1,24,0,0,0,0,0,1,0,
0,0,0,0,0,0,114,0,0,0,0,0,1,0,0,0,
0,0,0,2,26,0,0,0,0,0,1,0,0,0,0,0,
0,0,20,0,0,0,0,0,1,0,0,0,0,0,0,0,
82,0,0,0,0,0,1,0,0,0,0,0,0,0,190,0,
0,0,0,0,1,0,0,0,0,0,0,1,244,0,0,0,
0,0,1,0,0,0,0,0,0,1,62,0,0,0,0,0,
1,0,0,0,0,0,0,3,76,0,0,0,0,0,1,0,
0,0,0,0,0,0,226,0,0,0,0,0,1,0,0,0,
0,0,0,2,62,0,0,0,0,0,1,0,0,0,0,0,
0,1,124,0,0,0,0,0,1,0,0,0,0,0,0,1,
96,0,0,0,0,0,1,0,0,0,0,0,0,3,42,0,
0,0,0,0,1,0,0,0,0,0,0,1,216,0,0,0,
0,0,1,0,0,0,0,0,0,2,242,0,0,0,0,0,
1,0,0,0,0,0,0,2,178,0,0,0,0,0,1,0,
0,0,0,0,0,2,114,0,0,0,0,0,1,0,0,0,
0,0,0,2,88,0,0,0,0,0,1,0,0,0,0,0,
0,0,56,0,0,0,0,0,1,0,0,0,0,0,0,1,
188,0,0,0,0,0,1,0,0,0,0,0,0,1,158,0,
0,0,0,0,1,0,0,0,0,0,0,2,204,0,0,0,
0,0,1,0,0,0,0,0,0,0,152,0,0,0,0,0,
1,0,0,0,0,0,0,3,120,0,0,0,0,0,1,0,
0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,3,0,0,120,60,0,113,0,
109,0,108,0,15,4,207,168,220,0,84,0,97,0,98,0,
73,0,110,0,118,0,101,0,114,0,116,0,101,0,114,0,
46,0,113,0,109,0,108,0,10,11,209,5,60,0,83,0,
116,0,97,0,116,0,117,0,115,0,46,0,113,0,109,0,
108,0,13,5,198,49,220,0,83,0,116,0,97,0,116,0,
117,0,115,0,76,0,69,0,68,0,46,0,113,0,109,0,
108,0,16,4,128,20,60,0,67,0,104,0,111,0,105,0,
99,0,101,0,66,0,117,0,116,0,116,0,111,0,110,0,
46,0,113,0,109,0,108,0,16,15,31,116,92,0,83,0,
101,0,110,0,115,0,111,0,114,0,83,0,116,0,97,0,
116,0,117,0,115,0,46,0,113,0,109,0,108,0,15,5,
199,26,92,0,72,0,86,0,83,0,116,0,97,0,116,0,
117,0,115,0,76,0,69,0,68,0,46,0,113,0,109,0,
108,0,8,8,1,90,92,0,109,0,97,0,105,0,110,0,
46,0,113,0,109,0,108,0,13,2,123,198,124,0,84,0,
97,0,98,0,69,0,114,0,114,0,111,0,114,0,115,0,
46,0,113,0,109,0,108,0,16,2,202,234,92,0,67,0,
116,0,114,0,108,0,76,0,97,0,98,0,101,0,108,0,
76,0,69,0,68,0,46,0,113,0,109,0,108,0,14,6,
163,93,188,0,83,0,112,0,101,0,101,0,100,0,71,0,
97,0,117,0,103,0,101,0,46,0,113,0,109,0,108,0,
11,8,151,15,60,0,76,0,86,0,70,0,114,0,97,0,
109,0,101,0,46,0,113,0,109,0,108,0,14,8,105,205,
252,0,84,0,97,0,98,0,83,0,101,0,110,0,115,0,
111,0,114,0,115,0,46,0,113,0,109,0,108,0,12,13,
176,228,252,0,77,0,101,0,110,0,117,0,80,0,97,0,
103,0,101,0,46,0,113,0,109,0,108,0,11,12,29,81,
28,0,80,0,114,0,101,0,115,0,101,0,116,0,115,0,
46,0,113,0,109,0,108,0,11,8,175,15,60,0,72,0,
86,0,70,0,114,0,97,0,109,0,101,0,46,0,113,0,
109,0,108,0,16,5,215,248,92,0,67,0,65,0,78,0,
83,0,116,0,97,0,116,0,117,0,115,0,76,0,69,0,
68,0,46,0,113,0,109,0,108,0,15,4,188,116,188,0,
67,0,101,0,110,0,116,0,114,0,97,0,108,0,86,0,
105,0,101,0,119,0,46,0,113,0,109,0,108,0,10,8,
34,131,124,0,80,0,101,0,100,0,97,0,108,0,105,0,
46,0,113,0,109,0,108,0,10,11,104,113,92,0,66,0,
117,0,116,0,116,0,111,0,110,0,46,0,113,0,109,0,
108,0,12,10,216,80,28,0,76,0,97,0,98,0,101,0,
108,0,76,0,69,0,68,0,46,0,113,0,109,0,108,0,
14,2,77,89,252,0,84,0,97,0,98,0,66,0,97,0,
116,0,116,0,101,0,114,0,121,0,46,0,113,0,109,0,
108,0,10,9,205,169,188,0,80,0,114,0,101,0,115,0,
101,0,116,0,46,0,113,0,109,0,108,0,16,14,16,78,
92,0,84,0,97,0,98,0,84,0,101,0,108,0,101,0,
109,0,101,0,116,0,114,0,121,0,46,0,113,0,109,0,
108,0,15,9,81,201,156,0,83,0,116,0,97,0,116,0,
117,0,115,0,70,0,114,0,97,0,109,0,101,0,46,0,
113,0,109,0,108,0,7,0,151,88,156,0,76,0,69,0,
68,0,46,0,113,0,109,0,108,0,14,8,152,218,252,0,
82,0,97,0,99,0,105,0,110,0,103,0,80,0,97,0,
103,0,101,0,46,0,113,0,109,0,108,0,19,7,244,16,
220,0,84,0,101,0,108,0,101,0,109,0,101,0,116,0,
114,0,121,0,83,0,116,0,97,0,116,0,117,0,115,0,
46,0,113,0,109,0,108,0,13,15,45,4,92,0,84,0,
97,0,98,0,83,0,116,0,97,0,116,0,117,0,115,0,
46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _qml_TabStatus_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TelemetryStatus_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_RacingPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_LED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_StatusFrame_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TabTelemetry_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_Preset_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TabBattery_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_LabelLED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_Button_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_Pedali_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_CentralView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_CANStatusLED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_HVFrame_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_Presets_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_MenuPage_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TabSensors_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_LVFrame_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_SpeedGauge_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_CtrlLabelLED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TabErrors_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_HVStatusLED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_SensorStatus_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_ChoiceButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_StatusLED_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_Status_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _qml_TabInverter_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabStatus.qml"), &QmlCacheGeneratedCode::_qml_TabStatus_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TelemetryStatus.qml"), &QmlCacheGeneratedCode::_qml_TelemetryStatus_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/RacingPage.qml"), &QmlCacheGeneratedCode::_qml_RacingPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/LED.qml"), &QmlCacheGeneratedCode::_qml_LED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/StatusFrame.qml"), &QmlCacheGeneratedCode::_qml_StatusFrame_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabTelemetry.qml"), &QmlCacheGeneratedCode::_qml_TabTelemetry_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/Preset.qml"), &QmlCacheGeneratedCode::_qml_Preset_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabBattery.qml"), &QmlCacheGeneratedCode::_qml_TabBattery_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/LabelLED.qml"), &QmlCacheGeneratedCode::_qml_LabelLED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/Button.qml"), &QmlCacheGeneratedCode::_qml_Button_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/Pedali.qml"), &QmlCacheGeneratedCode::_qml_Pedali_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/CentralView.qml"), &QmlCacheGeneratedCode::_qml_CentralView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/CANStatusLED.qml"), &QmlCacheGeneratedCode::_qml_CANStatusLED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/HVFrame.qml"), &QmlCacheGeneratedCode::_qml_HVFrame_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/Presets.qml"), &QmlCacheGeneratedCode::_qml_Presets_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/MenuPage.qml"), &QmlCacheGeneratedCode::_qml_MenuPage_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabSensors.qml"), &QmlCacheGeneratedCode::_qml_TabSensors_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/LVFrame.qml"), &QmlCacheGeneratedCode::_qml_LVFrame_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/SpeedGauge.qml"), &QmlCacheGeneratedCode::_qml_SpeedGauge_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/CtrlLabelLED.qml"), &QmlCacheGeneratedCode::_qml_CtrlLabelLED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabErrors.qml"), &QmlCacheGeneratedCode::_qml_TabErrors_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/main.qml"), &QmlCacheGeneratedCode::_qml_main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/HVStatusLED.qml"), &QmlCacheGeneratedCode::_qml_HVStatusLED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/SensorStatus.qml"), &QmlCacheGeneratedCode::_qml_SensorStatus_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/ChoiceButton.qml"), &QmlCacheGeneratedCode::_qml_ChoiceButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/StatusLED.qml"), &QmlCacheGeneratedCode::_qml_StatusLED_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/Status.qml"), &QmlCacheGeneratedCode::_qml_Status_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/qml/TabInverter.qml"), &QmlCacheGeneratedCode::_qml_TabInverter_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
