//Created by Sushant Khurana (sushant@sukh.us)

#include "../interface/Interface.h"
#define ENCODING "utf-8"

#include <Python.h>
#include <iostream>
using namespace std;

static PyObject * string_lemmatizer(PyObject *self, PyObject *args) {
    const char *command;
    PyObject *lemmatized_set = PySet_New(NULL);
    if (PyArg_ParseTuple(args, "es", ENCODING, &command)) {
        //string sentence = command;
        //set<string> tokens = tokenize(sentence);
        //stemm(tokens, stemmed_set);
        const char* word = command;
        LemmatizePython lp;
        char* ret = lp.LemmatizeWord(word);
        PySet_Add(lemmatized_set, Py_BuildValue("O",
                    PyUnicode_AsRawUnicodeEscapeString(
                        PyUnicode_FromString(ret)
                        )));
    }
    return Py_BuildValue("O", lemmatized_set);
}

static PyMethodDef LemmaMethods[] = {
    {"pylemmatize",  string_lemmatizer, METH_VARARGS, "Lemmatizes String"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initpylemmatize(void) {
    (void) Py_InitModule("pylemmatize", LemmaMethods);
}

int main(void){
    return 0;
}
