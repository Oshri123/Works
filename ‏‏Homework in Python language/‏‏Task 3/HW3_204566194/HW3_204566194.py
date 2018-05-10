from functools import reduce
from operator import itemgetter

'''targil1'''
'''this function make object of Date with dispatch funcion'''
'''for example:
>>> d = make_date(2016, 12, 26)
>>> d
<function make_date.<locals>.dispatch at 0x02A880C0>
>>>year (d)
2016
>>>month (d)
December
>>>day (d)
26
>>>str_date(d)
'26th of December, 2016'
'''
def make_date(year,month,day):## the object include year,month and day
	if month<1 or month>12:
		month=1
	if day<1 or day >31:
		day=1
	def dispatch(date):
		if date=='year':
			return year
		elif date=='month':
			return month
		elif date=='day':
			return day
	return dispatch

def year(date):
	return date('year')

def month(date):
	months=['January','February','March','April','May','June','July','August','September','October','November','December']
	return months[date('month')-1]

def day(date):
	return date('day')

def str_date(date):
	return '{0}th of {1},{2}'.format(day(date),month(date),year(date))

'''targil 2'''

def enumerate(s):
    return s.split(';')
def clean(s):
    return list(filter(lambda x: '//' not in x and '..' not in x,s))
def complete_missing_values(s):
    return list(map(lambda x: x.replace('.','.txt') if x.endswith('.') else x ,s))

def data_processor_file_types(data):
    '''the function processed a string and caclulate how many times each file appears in the string'''
    '''for example:
    >>> data_preprocessing_file_types(data)
        the str is:[("py", 1), (“txt”, 2), ("zip", 2)]
    '''
    new_list =data.split(';')
    new_list = list(filter(lambda x: x if '//' not in x else None, new_list))
    new_list = list(map(lambda x: x.replace('..', '.'), new_list))
    new_list = list(map(lambda x: x.replace('.', '.txt') if x.endswith('.') else x, new_list))
    new_list = list(map(lambda x: x.rsplit('/', 1)if '.' in x else [x], new_list))
    new_list = list(filter(lambda x: x[1] if len(x)>1 else None, new_list))
    new_list = list(map(lambda x: x[1].split('.')if len(x)>1 else None, new_list))
    new_list = list(map(lambda x: x[1] if len(x)>1 else None, new_list))
    new_list = list(map(lambda x: (x, new_list.count(x)), new_list))
    new_list = list(set(new_list))
    print('the str is:', new_list)

'''targil 3'''

'''this function create new type that call 'currency' that include value and symbol with use of dispatch function'''
'''for example: 
>>> c = make_currency(10.50, '$')
>>> c('get_value')('amount')
10.50
>>> c('get_value')('symbol')
$
>>> c(‘set_value’)(‘amount’, 50)
>>> c(‘get_value’)(‘amount’)
50
>>> c('str')
$50.00
>>> c('convert')(lambda x: x*3.87, '%')
>>> c('str')
'%193.50' '''
def make_currency(value,symbol):
    v=value
    s=symbol
    def dispatch(message):
        def get_value(msg):## this func return value or symbol 
            if msg=="amount":
                return v
            elif msg=="symbol":
                return s
        def set_value(msg,x):## this func set value and symbol
            nonlocal v 
            nonlocal s
            if msg=="amount":
                v=x
            elif msg=="symbol":
                s=x
        def convert(func,sym):## this func update the new amount and the new symbol
            set_value('amount',func(v))
            set_value('symbol',sym)
        if message=="get_value":
            return get_value
        elif message=="set_value":
            return set_value
        elif message=="str":
            return '{0}{1}'.format(get_value('symbol'),get_value('amount'))
        elif message=="convert":
            return convert
    return dispatch
'''targil 4'''

'''this function create new type that call reverse_map_iterator '''
'''
for example:
>>> it = get_reverse_map_iterator((1,3,6), lambda x: 1/x)
>>> while it['has_more']():
it['next']()
0.16666666666666666
0.3333333333333333
1.0
>>> it = get_reverse_map_iterator((1,3,6))
>>> for i in range(1,6):
it['next']()
6
3
1
no more items
no more items
'''
def  get_reverse_map_iterator(list,func=lambda x:x):
    k=0
    n=0
    for i in list:##get the length of the list
        n+=1
    k=n
    def has_more():##check if the list has more
        nonlocal n
        n-=1
        if n+1==0:
            return False
        else:
            return True
    def next():##return the next value in the list
        nonlocal k
        k-=1
        if k>=0:
            return func(list[k])
        else:
            return "no more items"
    return {'has_more':has_more,'next':next}##return dic that include the two function ' has more' and ' next '

'''targil 5'''
'''
for example:
>>> my_list = make_mutable_rlist()
>>> for x in range(4)
my_list['push_first'](x)
>>> my_list['str']()
[3, 2, 1, 0]
>>> ext = make_mutable_rlist(my_list)
>>> my_list['extend'](ext)
>>> my_list['str']()
]3, 2, 1, 0, 3, 2, 1, 0]
>>> my_list['slice'](0,2)[‘str’]()
[3, 5]
>>> your_list = make_mutable_rlist(my_list)
>>> your_list['str']()
]3, 2, 1, 0, 3, 2, 1, 0]
>>> it = my_list['get_iterator']()
>>> while it['hasNext']():
print(it['next']())
3
2
1
0
3
2
1
0
'''
empty_rlist = None
def make_rlist(first,rest):
    return (first, rest)

def first(s):
    return s[0]

def rest(s):
    return s[1]

def len_rlist(s):
    length = 0
    while s != empty_rlist:
        s, length = rest(s), length + 1
    return length

def getitem_rlist(s, i):
    while i > 0:
        s, i = rest(s), i - 1
    return first(s)

def make_mutable_rlist(arg=empty_rlist):
    contents = empty_rlist
     
    def length():
        return len_rlist(contents)

    leng,leng2,n=length(),length(),0

    def get_item(ind):
        return getitem_rlist(contents, ind)

    def push_first(value):
        nonlocal contents
        contents = make_rlist(value, contents)

    def pop_first():
        nonlocal contents
        f = first(contents)
        contents = rest(contents)
        return f

    def str():
        new_list="["
        for i in range(length()):
            if i<length()-1:
                new_list+='{0},'.format(get_item(i))
            else:
                new_list+='{0}'.format(get_item(i))
        new_list+="]"
        return new_list

    def slice(first,last):
        new_list=make_mutable_rlist()
        if first>=0 and last-1 <=length():
            i=last-1
            while i>=first:
                new_list['push_first'](get_item(i))
                i-=1
  
        return new_list

    def extend(mutable_list):
        nonlocal contents
        len1=mutable_list['length']()
        for i in range(length()):
            push_first(mutable_list['get_item'](len1-1))
            len1-=1
    if(arg):
        contents=empty_rlist
        len1=arg['length']()
        for i in range (arg['length']()):
            len1-=1
            push_first(arg['get_item'](len1))

    def get_iterator():
        nonlocal leng,leng2
        leng,leng2,n=len_rlist(contents),len_rlist(contents),0
        return {'hasNext':hasNext,'next':next}

    def hasNext():
        nonlocal leng
        if(leng):
            leng-=1
            return True
        else:
            return False

    def next():
        nonlocal n
        if(n<=leng2):
            n+=1
            return(get_item(n-1))
    return {'length':length, 'get_item':get_item, 'push_first':push_first,'pop_first': pop_first, 'str':str,'slice':slice ,'extend':extend,'get_iterator':get_iterator}