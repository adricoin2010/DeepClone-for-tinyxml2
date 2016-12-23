/*
Small recursive function to clone a Node.

Original code by Adrian Guerrero Vera (adri.coin2010@gmail.com)

MIT License

Copyright (c) 2016 Adrian Guerrero Vera

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifdef DEEPCLONE

#include "DeepClone.h"

using namespace tinyxml2;

tinyxml2::XMLElement* DeepClone(tinyxml2::XMLNode* Original, tinyxml2::XMLNode* Destination, bool Safe) {

	if (Safe || Original -> ToElement() -> BoolAttribute("DeepClone") == false) {

		XMLDocument* DocXML = Destination -> GetDocument();

		XMLElement* SubOriginal;

		XMLElement* TempElement;
		const XMLAttribute* TempAttribute;

		//Clone Element with same name
		TempElement = DocXML -> NewElement(Original -> ToElement() -> Name());
		Destination -> InsertEndChild(TempElement);

		if (Safe) {

			TempElement -> SetAttribute("DeepClone", true);

		}

		TempAttribute = Original -> ToElement() -> FirstAttribute();

		//Clone all Attributes
		while (TempAttribute) {

			TempElement -> SetAttribute(TempAttribute -> Name(), TempAttribute -> Value());

			TempAttribute = TempAttribute -> Next();

		}

		//Clone Text
		if (Original -> ToElement() -> GetText()) TempElement -> SetText(Original -> ToElement() -> GetText());

		//Clone All Child
		SubOriginal = Original -> FirstChildElement();

		while (SubOriginal) {

			DeepClone(SubOriginal, TempElement, false);

			SubOriginal = SubOriginal -> NextSiblingElement();

		}

		if (TempElement -> BoolAttribute("DeepClone")) {

			TempElement -> DeleteAttribute("DeepClone");

		}

		return TempElement;

	}
	else
	{

		return NULL;

	}

}


#endif //DEEPCLONE