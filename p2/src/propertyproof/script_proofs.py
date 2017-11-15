
domain = ['c','r','p','.']

domain2 = ['c','r','p']

selection = { 'c' : {'c' : 'c' , 'r' : 'c', 'p' : 'c', '.' : 'c' },
              'r' : {'c' : 'c' , 'r' : 'r', 'p' : 'r', '.' : 'r' },
              'p' : {'c' : 'c' , 'r' : 'r', 'p' : 'p', '.' : 'p' },
              '.' : {'c' : 'c' , 'r' : 'r', 'p' : 'p', '.' : '.' }}

composition = { 'c' : {'c' : 'c' , 'r' : '.', 'p' : '.', '.' : '.' },
                'r' : {'c' : 'r' , 'r' : '.', 'p' : '.', '.' : '.' },
                'p' : {'c' : 'p' , 'r' : 'p', 'p' : 'p', '.' : '.' },
                '.' : {'c' : '.' , 'r' : '.', 'p' : '.', '.' : '.' }}

#####selection
#check associativity (x+y)+z = x+(y+z)
for x in domain:
    for y in domain:
        for z in domain:
            parte1r = selection[x][y]
            parte2r = selection[parte1r][z]

            parte1l = selection[y][z]
            parte2l = selection[x][parte1l]


            if parte2r != parte2l:
                print('fail associativity of selection')


#symmetry (x+y = x and y+x = y) => x = y
for x in domain:
    for y in domain:
            parte1 = selection[x][y]
            parte2 = selection[y][x]

            if( (parte1 == x) and (parte2 == y) ):
                if(parte1 != parte2):
                    print('fail anty-simmetry of selection')

#transitivity (x+y = x) and (y+z = y) => (x+z=x)
for x in domain:
    for y in domain:
        for z in domain:
            parte1 = selection[x][y]
            parte2 = selection[y][z]
            parte3 = selection[x][z]

            if( (parte1 == x) and (parte2 == y) ):
                if(parte3 != x):
                    print('fail transitivitys of selection')


#############composition
#check associativity (x+y)+z = x+(y+z) for composition
for x in domain:
    for y in domain:
        for z in domain:
            parte1r = composition[x][y]
            parte2r = composition[parte1r][z]

            parte1l = composition[y][z]
            parte2l = composition[x][parte1l]


            if parte2r != parte2l:
                print('fail associativity of composition' + ' |a = ' + str(x) + ' |b = ' + str(y) + ' |c =' + str(z))
