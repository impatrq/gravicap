<template>
<div class="grid-layout">
    <section class="grid-izquierda">
    <h2>UNA NUEVA FORMA DE <span class="elevar">ELEVAR TU ENERGIA</span></h2>
    <hr></hr>
    <p class="explicacion-izquierda">GraviCap es un proyecto innovador que busca aumentar la eficiencia de instalaciones de energía renovable usando baterías de gravedad.</p>
    </section>
    <section class="grid-derecha"> 
    <div class="beneficios"><h3>Beneficios</h3></div>
        <h4><img src="../../public/bateriafondo.png" class="batería">Una alternativa a baterías convencionales</h4>
            <p class="explicacion">Estas liberan compuestos peligrosos al ser desechadas, que se filtran en la tierra o son causantes de incendios. Junto con los problemas que conlleva su producción, resultan muy dañinas para el ambiente.</p>
        <h5><img src="../../public/rayofondo.png" class="rayo">Eficiencia energética</h5>
            <p class="explicacion">Usa un sistema para controlar la batería de gravedad,aumentando la eficiencia del suministro eléctrico, hace subir un peso con la energía excedente y cuando falta la deja caer para generar energía y utilizarla.</p>
        <h6><img src="../../public/relojfondo.png" class="reloj">Una vida útil más larga</h6>
        <p class="explicacion">Los ciclos de carga y descarga no afectan su capacidad máxima de carga, como sí ocurre en baterías convencionales. Usamos materiales resistentes en su construcción, resultando en el aumento de su vida útil. De esta forma, se reducen los costos a largo plazo.</p>
    </section>
</div>
</template>

<style scoped>
.grid-layout {
    display: grid;
    margin: 0;
    grid-template-columns: repeat(2, 40vw);
    gap: 10vw;
}
.grid-izquierda {
    text-align: left;
    width: 100%;
    margin: 0px;
    margin-left: 12%;
    height: 80vh;
}
hr {
    width: 10vw;
    justify-content: left;
    margin: 0px;
    border-color: #AC42EE;
}
.grid-derecha {
    justify-content: flex-end;
    width: 100%;
    padding-left: 50px;
    height: 80vh;
}
p {
    font-family: carlito;
}
h2, h3, h4, h5, h6 {
    font-family: carlito;
    margin-bottom: 0px;
}
h2, h3 {
    color: #66139A;
}
h2 {
    text-align:left ;
    padding-bottom: 2vh;
    padding-top: 2vh;
    margin-top: 0;
    font-size: 2.5vw;
}
.explicacion, .explicacion-izquierda {
    color: black;
    margin: 0;
}
h4, h5, h6 {
    font-size: 1.5vw;
}
h3 {
    font-size: 2.5vw;
    margin-top: 0px;
    padding-top: 2.3vh;
}
.explicacion-izquierda {
    padding-top: 5vh;
    color: #66139A;
    max-width: 100%;
    width: 50vw;
    height: 50vh;
    border-radius: 5%;
    margin-top: 5%;
    max-height: 50vh;
    font-size: 2.5vw;
}
.batería {
    width: 7%;
    height: 7%;
    margin-right: 2.5%;
    position: relative;
    border-radius: 100%;
}
.rayo {
    width: 7%;
    height: 7%;
    margin-right: 2.5%;
    border-radius: 100%;
    align-self: baseline;
}
.reloj {
    width: 7%;
    height: 7%;
    margin-right: 2.5%;
    border-radius: 100%;
}
.explicacion {
    font-size: 1vw;
    font-weight: bold;
}
.elevar {
    color: #9a138b;
}
.beneficios {
    font-size: 3vw;
}
@media screen and (max-width: 300px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 1.2rem;
    }
    h2 {
        font-size: 4vh
    }
}
@media screen and (max-width: 400px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 1.2rem;
    }
    h2 {
        font-size: 4vh
    }
}
@media screen and (max-width: 500px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 1.2rem;
    }
    h2 {
        font-size: 4vh;
    }
}
@media screen and (max-width: 600px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 700px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 800px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 900px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 1000px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 1100px) {
    h3 {
        font-size: 3vh;
    }
    h4, h5, h6 {
        font-size: 2vh;
    }
    .explicacion {
        font-size: 1.5vh;
    }
    .grid-derecha {
        padding: 0;
    }
    .explicacion-izquierda {
        font-size: 2vw;
    }
}
@media screen and (max-width: 320px) {
    body {
        height: 100vh;
    }
    .grid-layout {
    display: grid;
    margin: 0;
    grid-template-columns: 80vw;
    grid-template-rows: repeat(2 30vh 50vh);
    gap: 0;
    height: 80vh;
    }
    .grid-izquierda {
        margin-left: 10vw;
        height: 30vh;
    }
    .grid-derecha {
        margin-left: 10vw;
        height: 50vh;
        margin-bottom: 10vh;
    }
    h2 {
        font-size: 1.2rem; 
    }
    .explicacion-izquierda {
        font-size: 1.3rem;
        height: 10vh;
        padding: 0;
        width: 80vw;
    }
    h4, h5, h6 {
        padding: 0.1vh;
        font-size: 1.2rem
    }
    .explicacion {
        font-size: 1.2rem;
    }
}
    @media screen and (max-width: 375px) {
    body {
        height: 100vh;
    }
    .grid-layout {
    display: grid;
    margin: 0;
    grid-template-columns: 80vw;
    gap: 0;
    }
    .grid-izquierda {
        margin-left: 10vw;
        height: 30vh;
        margin-bottom: 17vh;
    }
    .grid-derecha {
        margin-left: 10vw;
        height: 30vh;
    }
    h2 {
        font-size: 1.2rem; 
    }
    .explicacion-izquierda {
        font-size: 1.3rem;
        height: 10vh;
        padding: 0;
        width: 80vw;
    }
    h4, h5, h6 {
        padding: 0.1vh;
        font-size: 0.7rem
    }
    .explicacion {
        font-size: 0.6rem;
    }
}
@media screen and (max-width: 425px) {
    body {
        height: 100vh;
    }
    .grid-layout {
    display: grid;
    margin: 0;
    grid-template-columns: 80vw;
    grid-template-rows: repeat(2 30vh 50vh);
    gap: 0;
    height: 80vh;
    }
    .grid-izquierda {
        margin-left: 10vw;
        height: 30vh;
    }
    .grid-derecha {
        margin-left: 10vw;
        height: 50vh;
        margin-bottom: 10vh;
    }
    h2 {
        font-size: 1.2rem; 
    }
    .explicacion-izquierda {
        font-size: 1.1rem;
        height: 10vh;
        padding: 0;
        width: 80vw;
    }
    h4, h5, h6 {
        padding: 0.1vh;
        font-size: 1.2rem
    }
    .explicacion {
        font-size: 1.2rem;
    }
}
</style>
<script>
export default {
  name: 'HomeView'
}
</script>
