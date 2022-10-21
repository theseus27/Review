from typing import (Union, Tuple, List,)
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

class Pokemon(BaseModel):
    name: str
    dexNum: int
    type: List[str]
    canEvolve: bool
    baseAttack: int
    baseDefense: int
    baseHP: int
    baseSpAttack: int
    baseSpDefense: int
    baseSpeed: int

@app.get("/")
def read_root():
    return {"Welcome to Pokemon"}

@app.get("/pokedex/{name}")
def display_info(name: str):
    return {name.details}
    
""" def read_query(name:str, query:Union[str, None] = None):
    return {"Name": name, "Query": query} """

@app.put("/pokedex/{name}")
def add_pokemon(name:str, new:Pokemon):
    return {"Pokemon:": name, "Details": new}