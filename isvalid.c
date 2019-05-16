typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _top;
	int _capacity;
}Stack;
void StackInit(Stack* ps) {
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*3);
	if (ps->_array == NULL) {
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_top = 0;
}

void StackDestory(Stack* ps) {
	assert(ps);
	if (ps->_array) {
		free(ps->_array);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}

void CheckCapacity(Stack* ps) {
	assert(ps);
	if (ps->_capacity == ps->_top) {
		int newCapacity = ps->_capacity * 2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)*newCapacity);
		if (pTemp == NULL) {
			assert(0);
			return;
		}
		for (int i = 0; i < ps->_top; ++i) {
			pTemp[i] = ps->_array[i];
		}
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

void StackPush(Stack* ps, SDataType data) {
	CheckCapacity(ps);
	ps->_array[ps->_top++] = data;
}
void StackPop(Stack* ps) {
	assert(ps);
	if (StackEmpty(ps))
		return;
	ps->_top--;
}
SDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_array[ps->_top - 1];
}
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0;
}
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}
bool isValid(char * s) {
	if (s == NULL)
		return true;
	int len = strlen(s);
	Stack st;
	StackInit(&st);
	for (int i = 0; i < len; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			StackPush(&st, s[i]);
		}
		else {
			if (StackEmpty(&st))
				return false;
			else {
				char ch = StackTop(&st);
				if ((ch == '('&&s[i] == ')') || (ch == '['&&s[i] == ']') || (ch == '{'&&s[i] == '}'))
					StackPop(&st);
				else
					return false;
			}
		}
	}
		if (StackEmpty(&st))
			return true;
		return false;
}
