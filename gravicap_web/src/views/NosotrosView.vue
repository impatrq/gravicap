<template>
<div class="container">
            <div class="grid-izquierda">
                <div class="quienes-somos">¿Quienes Somos?</div>
                <p class="texto-quienes-somos">Gravicap es un proyecto creado por estudiantes de 7°1 Aviónica de la escuela secundaria técnica n°7 o Impa. Nuestro objetivo es mostrarle al mundo una nueva forma menos dañina y mas eficiente de almacenar energía usando nuestro proyecto como ejemplo.</p>
            </div>
            <div class="grid-derecha">
                <h2>Integrantes</h2>
                <div class="presentacion-integrantes">
                    <div class="integrante"></br>Tomás - Aplicación<img class="yatu" src="../../public/tomas.png"></div>
                    <div class="integrante"></br>Fausto - Rezar<img class="yatu" src="../../public/fausto2.png"></div>
                    <div class="integrante"></br>Augusto - Estructura<img class="yatu" src="../../public/augusto.png"></div>
                    <div class="integrante"></br>Tatiana - Electrónica<img class="yatu" src="../../public/tatiana.png"></div>
                    <div class="integrante"></br>Gabriel - Redes sociales<img class="yatu" src="../../public/Logo.png"></div>
                    <div class="integrante"></br>Mariano - Página Web<img class="yatu" src="../../public/mariano2.png"></div>
                </div>
            </div>
        </div>
</template>

<style scoped>
.container {
    display: grid;
    height: 80vh;
    grid-template-columns: 0.7fr 1.5fr;
    grid-template-rows: 5fr;
    gap: 5vw;
    padding-left: 3vw;
    padding-right: 3vw;
    padding-top: 5vh;
    font-family: carlito;
}
.grid-izquierda {
    background-color:  #C287E8;
    border-radius: 5.5vw;
    max-height: 70vh;
}
.grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5vw;
    height: 70vh;
}
.quienes-somos {
    text-align: center;
    font-size: 3.5vw;
    padding-top: 2vh;
    color: #66139A;
}
h2 {
    text-align: center;
    font-size: 2vw;
    padding-top: 1.7vh;
}
.texto-quienes-somos {
    text-align: center;
    font-family: carlito;
    font-size: 3vw;
}
.presentacion-integrantes {
    display: grid;
    height: 30vh;
    grid-template-columns: 1fr 1fr 1fr;
    grid-template-rows: 20vh 20vh;
    grid-gap: 5.5vh 5.5vw;
    text-align: center;
    border: 0;
    justify-content: center;
    align-items: center;
}
.yatu {
    height: 10vw;
    width: 10vw;
    justify-content: center;
    align-self: center;
    align-items: center;
    border-radius: 50%;
    object-fit: cover;
    object-fit: contain;
}
.integrante {
    font-family: carlito;
    font-size: 1.2vw;
    padding: 0;
    margin: 0;
    overflow: hidden;
    display: flex;
    flex-direction: column;
    align-items: center;
    text-align: center;
}
.integrante img {
border-radius: 50%;
object-fit: cover;
}
@media screen and (max-width: 375px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.6vh;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5vw;
    height: 60vh;
    }
    .grid-izquierda {
    border-radius: 5.5vw;            
    }
    .yatu {
    height: 20vw;
    width: 20vw;
    }
}
@media screen and (max-width: 320px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.5vh;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5vw;
    height: 60vh;
    }
    .grid-izquierda {
    border-radius: 5.5vw;
    }
    .yatu {
                height:20vw;
                width: 20vw;
    }        
}
@media screen and (max-width: 425px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.5vh;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    border-radius: 5.5vw;
    }
    .grid-izquierda {
    border-radius: 5.5vw;
    } 
    .yatu {
                height: 20vw;
                width: 20vw;
    }
}
@media screen and (max-width: 768px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5%;
    height: 70vh;
    }
    .yatu {
                height: 15vw;
                width: 15vw;
    }
}
@media screen and (min-width:1440px) and (max-width: 1441px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2.5vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 800px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2.5vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 900px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2.5vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 1000px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2.5vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 500px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5%;
    height: 60vh;
    }                
}
@media screen and (max-width: 600px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 700px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 2.5vw;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
@media screen and (max-width: 400px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.5vh;
    }
    h2 {
        font-size: 2vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5%;
    height: 60vh;
    }                
}
@media screen and (max-width: 300px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.5vh;
    }
    h2 {
        font-size: 3vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
    .container {
    display: grid;
    height: 80vh;
    grid-template-columns: 80vw;
    grid-template-rows: 5fr;
    margin: 0;   
    padding-top: 5vh;
    padding-left: 10vw;        
    font-family: carlito;
    }
    .grid-derecha {
    background-color:  #C287E8;
    border-radius: 5.5%;
    height: 60vh;
    }                
}
@media screen and (min-width: 1024px) {
    .quienes-somos {
        font-size: 3vw;
    }
    .texto-quienes-somos {
        font-size: 1.8vw;
    }
    h2 {
        font-size: 3.5vh;
    }
    .integrante {
        font-size: 2vh;
        text-align: center;
    }
    .presentacion-integrantes {
        justify-content: center;
        align-items: center;
        text-align: center;
    }
}
</style>
