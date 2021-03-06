#ifndef QTMVVM_INPUTVIEWFACTORY_P_H
#define QTMVVM_INPUTVIEWFACTORY_P_H

#include "qtmvvmquick_global.h"
#include "inputviewfactory.h"

namespace QtMvvm {

class InputViewFactoryPrivate
{
public:
	QHash<QByteArray, QUrl> simpleInputs;
	QHash<QByteArray, QUrl> simpleDelegates;
	QHash<QByteArray, QByteArray> inputAliases;
	QHash<QByteArray, QByteArray> delegateAliases;
};

}

#endif // QTMVVM_INPUTVIEWFACTORY_P_H
