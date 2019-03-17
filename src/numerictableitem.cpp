/* numerictableitem.cpp: Numerically sortable table item.
 *
 * Copyright 2019 by Adrian "ArdiMaster" Welcker, distributed
 * under the MIT License - see file "LICENSE" for details.
 */

#include "numerictableitem.h"

bool NumericTableItem::operator<(const QTableWidgetItem &other) const {
	if (text() == "") return true;
	bool ok1, ok2;
	bool result = text().toDouble(&ok1) < other.text().toDouble(&ok2);
	if (!(ok1 && ok2)) return true;
	return result;
}