import React from "react";
import './App.css';
import {BrowserRouter, Routes, Route} from 'react-router-dom';
import Home from "./pages/home";
import ErrorPage from "./pages/error-page"

function App() {
  return (
    <div className = "App">
       <h1>Hello</h1>
       <BrowserRouter>
        <Routes>
          <Route path = "/" element = {<Home />} />
          <Route exact = {true} path = "*" element = {<ErrorPage />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
