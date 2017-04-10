#include <Python.h>
#include <stdio.h>

extern double step_function(const double *);

static PyObject *
study_dl_step_function(PyObject *self, PyObject *args)
{
    int sts;
    const double x;
    if (!PyArg_ParseTuple(args, "d", &x))
        return NULL;
    sts = step_function(&x);
    return Py_BuildValue("i", sts);
};

static PyMethodDef StudyDlMethod[] = {
    {"step_function",  study_dl_step_function, METH_VARARGS,
     "Execute step_function."},
    {NULL, 0, NULL, NULL}
};

static struct PyModuleDef study_dl = {
	PyModuleDef_HEAD_INIT,
	"study_dl",
	NULL,
	-1,
	StudyDlMethod
};

PyMODINIT_FUNC
PyInit_study_dl(void)
{
    return PyModule_Create(&study_dl);
};
