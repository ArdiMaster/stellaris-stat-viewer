//
// Created by Adrian Welcker on 2019-03-16.
//

#include "empire.h"

#include "model_private_macros.h"

using namespace Parsing;

namespace Galaxy {
	Empire::Empire(QObject *parent) : QObject(parent) {}

	qint64 Empire::getIndex() {
		return index;
	}

	const QString& Empire::getName() {
		return this->name;
	}

	double Empire::getMilitaryPower() {
		return this->militaryPower;
	}

	double Empire::getEconomyPower() {
		return this->economyPower;
	}

	double Empire::getTechPower() {
		return this->techPower;
	}

	Empire *Empire::createFromAst(Parsing::AstNode *tree, QObject *parent) {
		Empire *state = new Empire(parent);
		state->index = static_cast<qint64>(QString(tree->myName).toLongLong());
		AstNode *nameNode = tree->findChildWithName("name");
		CHECK_PTR(nameNode);
		state->name = nameNode->val.Str;
		AstNode *powerNode = tree->findChildWithName("military_power");
		CHECK_PTR(powerNode);
		state->militaryPower = powerNode->val.Double;
		powerNode = powerNode->nextSibling;
		if (qstrcmp(powerNode->myName, "economy_power") != 0) {
			powerNode = tree->findChildWithName("economy_power");
			CHECK_PTR(powerNode);
		}
		state->economyPower = powerNode->val.Double;
		powerNode = powerNode->nextSibling->nextSibling->nextSibling;
		if (qstrcmp(powerNode->myName, "tech_power") != 0) {
			powerNode = tree->findChildWithName("tech_power");
			CHECK_PTR(powerNode);
		}
		state->techPower = powerNode->val.Double;
		return state;
	}
}