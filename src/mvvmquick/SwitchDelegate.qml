import QtQuick 2.10
import QtQuick.Controls 2.3 as Controls
import QtQuick.Layouts 1.3

Controls.SwitchDelegate {
	id: _boolDelegate

	text: title

	function asBool(value) {
		if(typeof value == "string")
			return value === "true";
		else
			return Boolean(value);
	}

	Component.onCompleted: checked = asBool(inputValue)
	onCheckedChanged: {
		if(asBool(inputValue) !== checked)
			inputValue = checked;
	}

	contentItem: GridLayout {
		columns: 2
		rows: 2

		Controls.Label {
			id: _titleLabel
			text: _boolDelegate.text
			Layout.row: 0
			Layout.column: 0
			font.bold: true
			elide: Label.ElideRight
			Layout.fillWidth: true
		}

		Controls.Label {
			id: _textLabel
			visible: tooltip
			Layout.row: 1
			Layout.column: 0
			text: tooltip
			wrapMode: Text.WordWrap
			Layout.fillWidth: true
		}

		Item {
			Layout.row: 0
			Layout.column: 1
			Layout.rowSpan: 2
			Layout.minimumWidth: implicitWidth
			Layout.maximumWidth: implicitWidth
			implicitWidth: _boolDelegate.indicator.width + 14
		}
	}
}
