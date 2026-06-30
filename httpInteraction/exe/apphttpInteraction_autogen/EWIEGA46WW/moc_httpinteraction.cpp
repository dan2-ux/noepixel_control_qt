/****************************************************************************
** Meta object code from reading C++ file 'httpinteraction.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../httpinteraction.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpinteraction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15HttpInteractionE_t {};
} // unnamed namespace

template <> constexpr inline auto HttpInteraction::qt_create_metaobjectdata<qt_meta_tag_ZN15HttpInteractionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "HttpInteraction",
        "ledStatusChanged",
        "",
        "colorChanged",
        "brightnessChanged",
        "effectChanged",
        "getJson",
        "postJson",
        "changeLedStatus",
        "ls",
        "changeColor",
        "c",
        "changeBrightness",
        "b",
        "changeEffect",
        "e",
        "ledStatus",
        "color",
        "brightness",
        "effect"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'ledStatusChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'brightnessChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'effectChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getJson'
        QtMocHelpers::MethodData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'postJson'
        QtMocHelpers::MethodData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'changeLedStatus'
        QtMocHelpers::MethodData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Method 'changeColor'
        QtMocHelpers::MethodData<void(QString)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Method 'changeBrightness'
        QtMocHelpers::MethodData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Method 'changeEffect'
        QtMocHelpers::MethodData<void(QString)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'ledStatus'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'color'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 1),
        // property 'brightness'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 2),
        // property 'effect'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<HttpInteraction, qt_meta_tag_ZN15HttpInteractionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject HttpInteraction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15HttpInteractionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15HttpInteractionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15HttpInteractionE_t>.metaTypes,
    nullptr
} };

void HttpInteraction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HttpInteraction *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->ledStatusChanged(); break;
        case 1: _t->colorChanged(); break;
        case 2: _t->brightnessChanged(); break;
        case 3: _t->effectChanged(); break;
        case 4: _t->getJson(); break;
        case 5: _t->postJson(); break;
        case 6: _t->changeLedStatus((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->changeColor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->changeBrightness((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->changeEffect((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (HttpInteraction::*)()>(_a, &HttpInteraction::ledStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (HttpInteraction::*)()>(_a, &HttpInteraction::colorChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (HttpInteraction::*)()>(_a, &HttpInteraction::brightnessChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (HttpInteraction::*)()>(_a, &HttpInteraction::effectChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->ledStatus(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->color(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->brightness(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->effect(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLedStatus(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setColor(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setBrightness(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setEffect(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *HttpInteraction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpInteraction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15HttpInteractionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpInteraction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void HttpInteraction::ledStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HttpInteraction::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HttpInteraction::brightnessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HttpInteraction::effectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
