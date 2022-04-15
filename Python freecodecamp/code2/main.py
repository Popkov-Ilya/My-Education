import csv


# Item =========================================
# ==============================================
class Item:
    all = []

    def __init__(self, name: str, price: int, quantity: int = 0):
        self.__name = name
        self.price = price
        self.quantity = quantity
        Item.all.append(self)

    def __repr__(self):  # не путай с __str__
        return f"{self.__class__.__name__}('{self.name}', {self.price}, {self.quantity})"

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        self.__name = value

    @classmethod
    def inst_from_csv(cls):
        with open('items.csv', 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)
        for item in items:
            cls(
                name=item.get('name'),
                price=int(item.get('price')),
                quantity=int(item.get('quantity'))
            )

    @staticmethod
    def is_integer(num):
        if isinstance(num, float):
            return num.is_integer()
        else:
            return isinstance(num, int)


# Inherit (наследование) =======================
# ==============================================
class Phone(Item):
    def __init__(self, name: str, price: int, quantity: int = 0, broken: int = 0):
        super().__init__(name, price, quantity)
        self.broken = broken


# Основной код =================================
# ==============================================
item1 = Item("123", 1, 1)
print(item1.name)
