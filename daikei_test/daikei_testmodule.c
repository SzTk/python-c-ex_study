#include <Python.h>

extern int calc();

static PyObject *
daikei_test_run(PyObject *self, PyObject *args)
{
    int sts;
    if (!PyArg_ParseTuple(args, ""))
        return NULL;
    sts = calc();
    return Py_BuildValue("i", sts);
}

static PyMethodDef DaikeiMethods[] = {
    {"run",  daikei_test_run, METH_VARARGS,
     "Execute daikei_test."},
    {NULL, 0, NULL, NULL}
};

PyMODINIT_FUNC
initdaikei_test(void)
{
    (void) Py_InitModule("daikei_test", DaikeiMethods);
}
