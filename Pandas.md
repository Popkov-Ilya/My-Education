# Pandas



Сурс - https://youtu.be/ikOEn8jY2Is

```python
bit_df = pd.read_csv('/path/to/file.csv') #df = dataframe
bit_df.dtypes # выводит типы столбцов
bit_df['date'] = pd.to_datetime(bit_df.Timestamp, unit='s') # привести int к datetime
bit_df.set_index('date') # сделать новый стоблец date первичным ключем
	.rename(columns={'Open':'open', 'High':'hi'})
	.resample('d').agg({'open':'first', 'hi':'mean'}) #агрегация по дням, где mean = среднее, first = первый, очевидно
	.iloc[-1000:] # последние 1000 значений
    .assign(buy = lambda x: (x.close.shift(-1) > x.close).astype(int)) # сравнить с предыдущим
```

