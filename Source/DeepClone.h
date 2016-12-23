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

#include "tinyxml2.h"

/*
How to use this function:

In "Original" is where the node we want to clone.
In "Destination" is where the node is to be cloned, the node can be from same or the differents Documents.

"Safe" is a variable that is used within the function. It serves to not clone a self while doing the cloning.

The function return a "XMLElement*" with the finally Node.
*/

tinyxml2::XMLElement* DeepClone(tinyxml2::XMLNode* Original, tinyxml2::XMLNode* Destination, bool Safe = true);

#endif //DEEPCLONE