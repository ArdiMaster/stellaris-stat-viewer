/* military_view.cpp: Put empire military statistics into a table.
 *
 * Copyright 2019 by Adrian "ArdiMaster" Welcker, distributed
 * under the MIT License - see file "LICENSE" for details.
 */

#include "military_view.h"

#include "model/galaxy_state.h"
#include "model/empire.h"
#include "model/fleet.h"
#include "numerictableitem.h"

MilitaryView::MilitaryView(QWidget *parent) : QTableWidget(parent) {
	setColumnCount(2);
	QStringList headers;
	headers << tr("Name") << tr("Total Fleet Power");
	setHorizontalHeaderLabels(headers);
}

void MilitaryView::modelChanged(const Galaxy::State *newState) {
	setSortingEnabled(false);
	const QMap<qint64, Galaxy::Fleet*> &fleets = newState->getFleets();
	QMap<Galaxy::Empire *, double> empireTotalMilitary;
	for (auto fit = fleets.cbegin(); fit != fleets.cend(); fit++) {
		Galaxy::Empire *owner = fit.value()->getOwner();
		empireTotalMilitary[owner] = empireTotalMilitary.value(owner, 0) + fit.value()->getMilitaryPower();
	}
	setRowCount(empireTotalMilitary.size());
	int i = 0;
	for (auto it = empireTotalMilitary.cbegin(); it != empireTotalMilitary.cend(); it++) {
		QTableWidgetItem *itemName = new QTableWidgetItem(it.key()->getName());
		setItem(i, 0, itemName);
		NumericTableItem *itemMilitary = new NumericTableItem(tr("%1").arg(it.value()));
		setItem(i++, 1, itemMilitary);
	}
	setSortingEnabled(true);
}
