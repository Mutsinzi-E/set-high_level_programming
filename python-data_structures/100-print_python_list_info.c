#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <stdio.h>

/**
 * print_python_list_info - prints information about Python lists
 * @p: Python object
 *
 * Return: Nothing
 */
void print_python_list_info(PyObject *p)
{
	Py_ssize_t size;
	Py_ssize_t allocated;
	Py_ssize_t i;
	PyListObject *list;

	list = (PyListObject *)p;

	size = Py_SIZE(list);
	allocated = list->allocated;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", allocated);

	for (i = 0; i < size; i++)
	{
		printf("Element %ld: %s\n",
		       i,
		       Py_TYPE(PyList_GET_ITEM(p, i))->tp_name);
	}
}
