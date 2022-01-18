# Elasticsearch + Python

Сурс – https://www.elastic.co/guide/en/elasticsearch/reference/current/index.html

## Python

```python
# http
es = Elasticsearch(["localhost"], http_auth=('login', 'password'))
# https
es = Elasticsearch(["localhost"], http_auth=('login', 'password'), use_ssl=True, verify_certs=False 
print(es.indices.exists(index=my_index)) # проверить наличие индекса
```

```python
doc1 = {
     "ip": "172.168.0.1",
     "name": "Some Event"
     }
print(es.index(index="python", document=doc1)) # добавить запись
```

```python
res = es.get(index=my_index, id="1") # получение по индексу
res = es.search(index=my_index, size=10, from_=0, query={"match": {"name": "XXX"}}) # поиск
print(res['_source']['name'])
```



## Elasticsearch

```json
// обычный запрос на совпадение
"query": {
    "bool": {
    	"must": [
            { "match": { "name": "some text" } }, // поиск some или text
            { "match_phrase": { "some text" } } // поиск именно "some text"
    }
}
```

```json
// запрос на интервал
"query": {
    "range": {
        "@timestamp": {
            "gte": "2022-01-11",
            "lte": "now-15m"
        }
    }
}
```

```json
// регулярка
"query": {
    "regexp":{
        "name": ".*"
    }
}
```

```json
// агрегация
"aggs": {
    "my-first-agg-name": {
      "terms": { // точная
         "size": 5, 
		"field": "my-field"
      }
    },
    "my-second-agg-name": {
      "avg": { // среднее
        "field": "my-other-field"
      }
    }
  }
```

