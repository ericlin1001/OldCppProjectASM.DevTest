#include <cstdlib>
#include <iostream>
using namespace std;
#include"Python.h"
//
  /*  int CallPyFunction(const char *pszModuleName,  
    const char *pModulFuncName,  
    const char *pParam[],  
    const int nCount)  
    {  
    PyObject *pName = NULL;  
    PyObject *pModule = NULL;  
    PyObject *pDict = NULL;  
    PyObject *pFunc = NULL;  
    PyObject *pParams = NULL;  
    PyObject *pCurrParam = NULL;   
    int i = 0;  
    pName = PyString_FromString(pszModuleName);   
    pModule = PyImport_Import(pName);   
    pDict = PyModule_GetDict(pModule);  
    pFunc = PyDict_GetItemString(pDict, pModulFuncName);   
    pParams = PyTuple_New(nCount);  
    i = 0;  
    while (i < nCount)  
    {  
    pCurrParam = PyString_FromString(pParam[i]);   
    PyTuple_SetItem(pParams, i, pCurrParam);   
    i++;  
    }  
    PyObject *pFtp= PyObject_CallObject(pFunc, pParams);  
    return true;  
    }   */
    //
int main(int argc, char *argv[])
{
    //note:this can't compile!!!!
    /* TODO (eric#1#): Read manual of Python and learning how to embed 
                       python in C++ programs */
    
  Py_Initialize();
    PyRun_SimpleString("import sys");   
PyRun_SimpleString("sys.path.append('./')");   
PyRun_SimpleString("import os");  
PyRun_SimpleString("import string"); 

 Py_Finalize();
    system("PAUSE");
    return EXIT_SUCCESS;
}
