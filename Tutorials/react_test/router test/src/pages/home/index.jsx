import React, { useEffect, useState } from 'react';
import FastAPIClient from '../../client';
import config from '../../config';
import PokemonTable from "../../components/PokemonTable"
import Header from "../../components/Header";
import Footer from "../../components/Footer";
import Loader from '../../components/Loader';

const client = new FastAPIClient(config);

export default function Home() {
  const [loading, setLoading] = useState(true)
  const [pokemonSet, setPokemon] = useState([])

  const fetchPokemon = async () => {
    setLoading(true)

    client.getAllPokemon("*").then((data) => {
      setLoading(false)
      setPokemon(data?.results)
    });
  }

  useEffect(() => {
    fetchPokemon()
  }, [])

  if (loading)
    return <Loader />

  //Main stuff that's getting printed
  return (
    <>
      <section className="bg">
        <Header />

        <div className = "container">
          <div className = "flex flex-col flex-wrap text-white">
            <h1 className = "text-3x1 font-medium text-white">
              Pokemon Team Optimizer
            </h1>  
          </div> 

          <div className="pokemonTable">
            <PokemonTable
                pokemon = {pokemonSet}
            />
          </div>
        </div>
        <Footer />
      </section>
    </>
  )
}