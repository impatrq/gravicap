<script setup>
import { RouterLink, RouterView } from 'vue-router'
import HelloWorld from './components/HelloWorld.vue'
</script>

<template>
  <header>
    <div class="logo"><router-link to="home"><img src="../public/Logo.png" class="logoimg"></router-link></div>
    <div class="h1"><router-link to="home"> <h1> GRAVICAP</h1></router-link></div>
    <div class="sobrenosotros"><router-link to="sobre_nosotros"><p class="texto-header">SOBRE NOSOTROS</p></router-link></div>
    <div class="galeria"><router-link to="galeria"><p class="texto-header">GALERIA</p></router-link></div>
    <div class="contactanos"><router-link to="contactanos"><p class="texto-header">✉ CONTACTANOS</p></router-link></div>
    <div class="instagram"><a href="https://www.instagram.com/gravi.cap/"><img src="../public/instagram4.png" class="instagramimg"></a></div>
    <div class="github"><a href="https://github.com/impatrq/gravicap"><img src="../public/github.png" class="githubimg"></a></div>
  </header>
  <RouterView />
</template>

<style>
header {
    display: grid;
    grid-template-columns: repeat(7, auto);
    height: 15vh;
    width: 97vw;
    background-color:  #C287E8;
    text-align: center;
    justify-content: space-around;
    align-items: center;
    margin: 0;
    border-radius: 3vw ;
    margin-left: 1.6vw;
}
h1 {
    font-family: carlito;
    margin-left: 0px;
    font-weight: bolder;
    color: #66139A;
    font-size: 2.3vw;
}
.logoimg {
    width: 5.5vw;
    height: 5.5vw;
    margin: 0;
    object-fit: contain; 
}
.githubimg {
    width: 4.2vw;
    height: 4.2vw;
    margin: 0;
    object-fit: contain; 
}
.instagramimg {
      width: 4.5vw;
    height: 4.5vw;
    margin: 0;
    object-fit: contain; 
}
.texto-header {
    color: #66139A;
    font-weight: bold;
    padding-left: 4vw;
    font-size: 1.2vw;
}
nav {
  width: 100%;
  font-size: 2vw;
  text-align: center;
  margin-top: 2rem;
}
nav a.router-link-exact-active {
  color: var(--color-text);
}
nav a.router-link-exact-active:hover {
  background-color: transparent;
}
nav a {
  display: inline-block;
  padding: 0 1rem;
  border-left: 1px solid var(--color-border);
}
nav a:first-of-type {
  border: 0;
}
@media (min-width: 1024px) {
  header {
    display: grid;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }
  header .wrapper {
    display: grid;
    place-items: flex-start;
    flex-wrap: wrap;
  }
  nav {
    text-align: left;
    margin-left: -1vw;
    font-size: 1vw;
    padding: 1vw 0;
    margin-top: 1vh;
  }
}
@media screen and (max-width: 320px) {
  .logoimg {
    object-fit: contain;
    height: 6vh;
    width: 6vw;
  }
  h1 {
    font-size: 4vw;
  }
  .texto-header {
    font-size: 1.3vh;
    padding-left: 1vw;
  }
  .githubimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
  .instagramimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
}
body {
    margin: 0;
    background-color: #fcedf2;
}
@media screen and (max-width: 375px) {
  .logoimg {
    object-fit: contain;
    height: 6vh;
    width: 6vw;
  }
  h1 {
    font-size: 4vw;
  }
  .texto-header {
    font-size: 1.3vh;
    padding-left: 1vw;
  }
  .githubimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
  .instagramimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
}
@media screen and (max-width: 425px) {
  .logoimg {
    object-fit: contain;
    height: 6vh;
    width: 6vw;
  }
  h1 {
    font-size: 4vw;
  }
  .texto-header {
    font-size: 1.3vh;
    padding-left: 1vw;
  }
  .githubimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
  .instagramimg {
    object-fit: contain;
    height: 5vh;
    width: 5vw;
  }
}
</style>
