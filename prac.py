import copy
d1 = {'a': 1, 'b': [10, 20]}

# Method 1
d2 = d1.copy()

# Method 2
d3 = dict(d1)

d3['a'] = 100
print(d1)   # {'a': 1, 'b': [10, 20]}   ✅ independent key

d3['b'].append(30)
print(d1)   # {'a': 1, 'b': [10, 20, 30]} ❌ shared reference
