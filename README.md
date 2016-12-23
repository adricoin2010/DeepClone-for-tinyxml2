# DeepClone for Tinyxml2
Small recursive function to clone a Node.

```c++
/*
How to use this function:

In "Original" is where the node we want to clone.

In "Destination" is where the node is to be cloned, the node can be from same or the differents Documents.

"Safe" is a variable that is used within the function. It serves to not clone a self while doing the cloning.
*/

void DeepClone(tinyxml2::XMLNode* Original, tinyxml2::XMLNode* Destination, bool Safe = true);
```

