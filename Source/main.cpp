#include "DeepClone.h"

#include <iostream>

using namespace std;
using namespace tinyxml2;

int main() {

	XMLDocument OriginalXML;
	XMLElement* OriginalElement;

	XMLDocument DestinoXML;
	XMLElement* DestinoElement;

	if (OriginalXML.LoadFile("Example/simple.xml")) {

		cout << "ERROR: File XML no exist" << endl;

	}

	OriginalElement = OriginalXML.FirstChildElement() -> FirstChildElement();

	DestinoElement = DestinoXML.NewElement(OriginalXML.FirstChildElement() -> Name());

	DestinoXML.InsertFirstChild(DestinoElement);

	DeepClone(OriginalElement, DestinoElement);

	DestinoXML.SaveFile("Example/new.xml");

}