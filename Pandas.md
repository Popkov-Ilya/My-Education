# Pandas





### |	Задание данных

```python
%%time # замерить время выполнения в юпитере
df = pd.read_csv('/path/to/file.csv', index_col=0) #df = dataframe
df = pd.read_json('data.json')
df = pd.DataFrame(data) # data это массив

df = pd.DataFrame({'Bob': ['I liked it.', 'It was awful.'], 'Sue': ['Pretty good.', 'Bland.']}, index=['Product A', 'Product B']) # создать табличку с нуля (Bob, Sue - столбцы, Product A, Product B - строки)

df = pd.Series([1, 2, 3, 4, 5]) # список
df = pd.Series([30, 35, 40], index=['2015 Sales', '2016 Sales', '2017 Sales'], name='Product A') # name - название таблицы, index - ее заголовки строк - 30, 35, 40 - данные


df.insert(1, "age", [50, 40, 30]) # позиция, название, данные
newdf = df.assign(name = ["Emil", "Tobias", "Linus"]) # новый фрейм с еще одним стобцом
newdf = df1.append(df2) # новый фрейм из двух прежних
newdf = df1.join(df2) # то же самое


print(df.dtypes) # выводит типы столбцов
print(dir(df)) # вывести атрибуты дата-фрейма
print(df.info())  # информация о данных
print(df.shape) # размеры матрицы
print(df.columns) # названия столбцов
```



### |	Вывод данных

```python
print(df.loc[0]) # выведет только первый столбец
print(df.loc[[0, 1]]) # выведет два первых, очеивидно
pd.options.display.max_rows = 9999 # узменение максимума выведения строк
print(df.head(10)) # первые 10 строк
```



### |	Очистка данных

```python
new_df = df.dropna() # удаляет строки с пустыми ячейками. dropna создает новый фрейм и не трогает рабочий
df.dropna(inplace = True) # а теперь удалит из исходного
df.fillna(130, inplace = True) # заполняет пустые места значением 130
df["Calories"].fillna(130, inplace = True) # только для столбца

x = df["Calories"].mean() # mean/median/mode[0]
df["Calories"].fillna(x, inplace = True)


# пройтись по строкам и удалить строку
for x in df.index:
  if df.loc[x, "Duration"] > 120:
    df.drop(x, inplace = True)
    
# ==================================================
newdf = df.drop("age", axis='columns') # columns/index - очистка строки или столбца
```



### |	Приведение форматов

```python
df['Date'] = pd.to_datetime(df['Date']) # преобразовать формат столбца
df.dropna(subset=['Date'], inplace = True) # после преобразования удалить все, что не смогло преобразоваться

```



### |	Дубликаты

```python
print(df.duplicated()) # True / False
df.drop_duplicates(inplace = True) # удалить повторяющихся

```



### |	Выборки

```python
df = pd.DataFrame(data) # where
newdf = df.where(df["age"] > 30)

df = pd.DataFrame(data, index = idx) # сортировка по индексу ( заголовку строки)
newdf = df.sort_index()

df = pd.DataFrame(data) # сортировка по столбцу
newdf = df.sort_values(by='age')


print(df.groupby(["car"]).mean()) # группировка по столбцу car и нахождению среднего там где возможно

newdf = df.mask(df["age"] > 30) # все, что не входит в условие становится NaN

```



### |	Обработка

```python
df = pd.DataFrame(data) # для каждой строки выполнится функция calc_sum(array)
x = df.apply(calc_sum)
# =====================================
print(df.diff()) # вычислить значение разности с предыдущей строкой (в первой строке будут NaN)
```





### |	Прочее

```python
df.corr() # корелляция - не понятно
# ===============================================================
df.plot() # линейный график
df.plot(kind = 'scatter', x = 'Duration', y = 'Calories') # точечный
plt.show()

df["Duration"].plot(kind = 'hist') # гистограммный
# ===============================================================
print(df.sample()) # случайное значеие из матрицы
```





### |	Пример обработки

```python
df = (
    df.set_index('date') # сделать новый стоблец date первичным ключем
		.rename(columns={'Open':'open', 'High':'hi'})
		.resample('d').agg({'open':'first', 'hi':'mean'}) #агрегация по дням, где mean = среднее, first = первый, очевидно
	.iloc[-1000:] # последние 1000 значений
    .assign(buy = lambda x: (x.close.shift(-1) > x.close).astype(int)) # сравнить с предыдущим
)
```





