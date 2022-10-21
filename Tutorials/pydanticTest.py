from pydantic import BaseModel, ValidationError, validator

class person(BaseModel):
    age: int

data = {
    'age': '18',
}

#So basically it throws an error if the initial 'data' isn't an int, but it doesn't care if you change it later

try:
    theseus = person(**data)
    theseus.age = 19
    print(theseus.age)
    theseus.age = "what's up"
    print("Check 1")
    print(theseus.age)
    print("Check 2")
except ValidationError as e:
    print(e.json())