<template>
<div class="container">
            <div class="grid_1">
                <p>Placa PCB del MPPT</p>
                <img class="imagenes" src="../../public/PCB MPPT.png" />
            </div>
            <div class="grid_2">
                <p>Creación del peso</p>
            <img class="imagenes" src="../../public/creacionPeso (1).png">
            </div>
            <div class="grid_3">
                <p>Estructura sin pintar</p>
            <img class="imagenes" src="../../public/estructuraSinPintar.png">
            </div>
            <div class="grid_4">
                <p>Estructura pintada</p>
            <img class="imagenes" src="../../public/estructuraPintada (2).png">
            </div>
            <div class="grid_5">
                <p>Visita a Radio Vox</p>
            <img class="imagenes" src="../../public/visitaRadioVox.png">
            </div>
            <div class="grid_6">
                <p>Visita a Vale Doble Radio</p>
            <img class="imagenes" src="../../public/visitaValeDobleRadio.png">
            </div>
            <div class="grid_7">
                <p>Visita de BernalTV</p>
            <img class="imagenes" src="../../public/bernalTv.png">
            </div>
            <div class="grid_8">
                <p>Prueba de paneles solares</p>
            <img class="imagenes" src="../../public/placeholder.jpg">
            </div>
        </div>
</template>
<style scoped>
.container {
    display: grid;
    height: 80vh;
    grid-template-columns: 22vw 22vw 22vw 22vw;
    grid-template-rows: 35vh 35vh;
    gap: 2vw;
    padding-left: 3vw;
    padding-right: 3vw;
    padding-top: 5vh;
    font-family: carlito;
}
.grid_1 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_2 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_3 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_4 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_5 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_6 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_7 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
.grid_8 {
    display: flex;
    background-color:  #C287E8;
    height: 100%;
    width: 100%;
    border-radius: 5%;
    justify-content: center;
    align-items: center;
    flex-direction: column;
}
p {
    font-family: carlito;
    text-align: center;
    align-self: center;
    justify-content: center;
    align-content: center;
    background-color: #fcedf2;
    width: 75%;
    height: 15%;
    border-radius: 1rem;
    padding: 0;
    margin-top: 0.5vh;
    font-size: 3vh;
}
.imagenes {
    height: 22vh;
    width: 20vw;
    object-fit: contain;
    padding: 0;
    max-width: 100%;
    margin: 0;
    align-items: center;
    justify-content: center;
}
@media only screen and (max-width: 768px) {
    .container {
        grid-template-columns: 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
    }
    .imagenes {
        height: 70%;
        width: 380px; 
        object-fit: contain;
        padding: 0;
        text-align: center;
        max-height: 22vh;
    }
    p {
        font-size: 1.5vw;
    }
}
@media only screen and (max-width: 1024px) {
    .container {
        grid-template-columns: 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
    }
    .imagenes {
        height: 70%;
        width: 40vw; 
        object-fit: contain;
        padding: 0;
        max-width: 100%;
        text-align: center;
    }
    p {
        font-size: 1.5vw;
    }
}
@media only screen and (max-width: 1440px) {
    .container {
        grid-template-columns: 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
    }
    .imagenes {
        height: 70%;
        width: 40vw; 
        object-fit: contain;
        padding: 0;
        max-width: 100%;
        text-align: center;
    }
    p {
        font-size: 1.5vw;
    }
}

@media only screen and (max-width: 2560px) {
    .container {
        grid-template-columns: 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr 1fr 1fr 1fr 1fr 1fr;
    }
    .imagenes {
        height: 70%;
        width: 380px; 
        object-fit: contain;
        padding: 0;
        max-width: 100%;
        text-align: center;
        max-height: 22vh;
    }
    p {
        font-size: 1.5vw;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
                p {
                            margin-bottom: 1.748vh;
                }
                .imagenes {
                            margin-bottom: 0.5vh;
                }
    }
}


@media only screen and (max-width: 375px) {
    .container {
    display: grid;
    grid-template-columns: 80vw; 
    grid-template-rows: auto; 
    gap: 1rem; 
    padding: 0; 
    align-self: center;
    align-items: center;
    justify-content: center;
    row-gap: 5vh;
    }
    .imagenes {
    width: 90%; 
    height: auto; 
    max-width: 100%; 
    object-fit: contain;
    border-radius: 1.5rem;
    }
    p {
        font-size: 1rem;
        text-align: center;
    }
    .grid {
        display: flex;
        width: 100%; 
        justify-content: center;
        align-items: center;
        align-self: center;
        margin-top: 5vh;
        padding: 0;
        margin-bottom: 10vh;
    }
    .grid_1 {
        margin-top: 5vh;
        margin-bottom: 2vh;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
    padding-bottom: 2vh;
    }
    header {
        margin-bottom: 5vh;
    }
}


@media only screen and (max-width: 425px) {
    .container {
    display: grid;
    grid-template-columns: 80vw; 
    grid-template-rows: auto; 
    gap: 1rem; 
    padding: 0; 
    align-self: center;
    align-items: center;
    justify-content: center;
    row-gap: 5vh;
    }
    .imagenes {
    width: 90%; 
    height: auto; 
    max-width: 100%; 
    object-fit: contain;
    border-radius: 1.5rem;
    }
    p {
        font-size: 1rem;
        text-align: center;
    }
    .grid {
        display: flex;
        width: 100%; 
        justify-content: center;
        align-items: center;
        align-self: center;
        margin-top: 5vh;
        padding: 0;
        margin-bottom: 10vh;
    }
    .grid_1 {
        margin-top: 5vh;
        margin-bottom: 2vh;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
    padding-bottom: 2vh;
    }
    header {
        margin-bottom: 5vh;
    }
}


@media only screen and (max-width: 480px) {
    .container {
    display: grid;
    grid-template-columns: 80vw; 
    grid-template-rows: auto; 
    gap: 1rem; 
    padding: 0; 
    align-self: center;
    align-items: center;
    justify-content: center;
    row-gap: 5vh;
    }
    .imagenes {
    width: 90%; 
    height: auto; 
    max-width: 100%; 
    object-fit: contain;
    border-radius: 1.5rem;
    }
    p {
        font-size: 1rem;
        text-align: center;
    }
    .grid {
        display: flex;
        width: 100%; 
        justify-content: center;
        align-items: center;
        align-self: center;
        margin-top: 5vh;
        padding: 0;
        margin-bottom: 10vh;
    }
    .grid_1 {
        margin-top: 5vh;
        margin-bottom: 2vh;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
    padding-bottom: 2vh;
    }
    header {
        margin-bottom: 5vh;
    }
}


@media only screen and (max-width: 550px) {
    .container {
    display: grid;
    grid-template-columns: 80vw; 
    grid-template-rows: auto; 
    gap: 1rem; 
    padding: 0; 
    align-self: center;
    align-items: center;
    justify-content: center;
    row-gap: 5vh;
    }
    .imagenes {
    width: 90%; 
    height: auto; 
    max-width: 100%; 
    object-fit: contain;
    border-radius: 1.5rem;
    }
    p {
        font-size: 1rem;
        text-align: center;
    }
    .grid {
        display: flex;
        width: 100%; 
        justify-content: center;
        align-items: center;
        align-self: center;
        margin-top: 5vh;
        padding: 0;
        margin-bottom: 10vh;
    }
    .grid_1 {
        margin-top: 5vh;
        margin-bottom: 2vh;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
    padding-bottom: 2vh;
    }
    header {
        margin-bottom: 5vh;
    }
}

            
@media only screen and (max-width: 320px) {
    .container {
    display: grid;
    grid-template-columns: 80vw; 
    grid-template-rows: auto; 
    gap: 1rem; 
    padding: 0; 
    align-self: center;
    align-items: center;
    justify-content: center;
    row-gap: 5vh;
    }
    .imagenes {
    width: 90%; 
    height: auto; 
    max-width: 100%; 
    object-fit: contain;
    border-radius: 1.5rem;
    }
    p {
        font-size: 1rem;
        text-align: center;
    }
    .grid {
        display: flex;
        width: 100%; 
        justify-content: center;
        align-items: center;
        align-self: center;
        margin-top: 5vh;
        padding: 0;
        margin-bottom: 10vh;
    }
    .grid_1 {
        margin-top: 5vh;
        margin-bottom: 2vh;
    }
    .grid_2, .grid_3, .grid_4, .grid_5, .grid_6, .grid_7, grid_8 {
    padding-bottom: 2vh;
    }
    header {
        margin-bottom: 5vh;
    }
}

            
</style>
