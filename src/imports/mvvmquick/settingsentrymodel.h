#ifndef QTMVVM_SETTINGSENTRYMODEL_H
#define QTMVVM_SETTINGSENTRYMODEL_H

#include <QtCore/QAbstractListModel>

#include <QtMvvmCore/SettingsViewModel>
#include <QtMvvmCore/SettingsElements>

#include <QtMvvmQuick/InputViewFactory>

namespace QtMvvm {

class SettingsEntryModel : public QAbstractListModel
{
	Q_OBJECT

public:
	enum Roles {
		GroupRole = Qt::UserRole + 1,
		KeyRole,
		TypeRole,
		TitleRole,
		ToolTipRole,
		DelegateUrlRole,
		SettingsValueRole,
		PropertiesRole,
		SearchKeysRole
	};
	Q_ENUM(Roles)

	static const QList<int> FilterRoles;

	explicit SettingsEntryModel(QObject *parent = nullptr);

	void setup(const SettingsElements::Section &setup, SettingsViewModel *viewModel, InputViewFactory *factory);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role) override;
	QHash<int, QByteArray> roleNames() const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
	struct EntryInfo : public SettingsElements::Entry {
	public:
		EntryInfo(SettingsElements::Entry entry = {}, const QUrl &delegateUrl = {}, SettingsElements::Group group = {});

		QUrl delegateUrl;
		SettingsElements::Group group;
	};

	SettingsViewModel *_viewModel;
	QList<EntryInfo> _entries;
};

}

#endif // QTMVVM_SETTINGSENTRYMODEL_H
