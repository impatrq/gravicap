<template>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<div class="contactanos-contenedor">
            <form action="https://api.web3forms.com/submit" method="POST" class="contactanos-izquierda">
                <div class="contactanos-izquierda-title">
                    <h1>Contáctanos</h1>
                </div>
                <input type="hidden" name="access_key" value="2d8e5b52-421c-4cee-bd21-113535d94d93">
                <input type="text" name="name" placeholder="Tu Nombre" class="contactanos-inputs" required>
                <input type="email" name="email" placeholder="Tu Email" class="contactanos-inputs" required>
                <textarea name="mensaje" placeholder="Tu Mensaje" class="contactanos-inputs" required></textarea>
                <button type="submit">Enviar</button>
            </form>
</div>
</template>

<style scoped>
    *{
    padding: 0;
    margin: 0;
    box-sizing: border-box;
    font-family: carlito;
}
body {
    background-color: #fcedf2;
}
.contactanos-inputs {
    background-color:  #C287E8;
    border-radius: 1vw;
    border: 0;
    margin-bottom: 0.5vh;
    margin-top: 0.5vh;
    padding-left: 5%;
}
.contactanos-contenedor {
    height: 80vh;
    width: 100vw;
    display: grid;
    align-items: center;
    justify-content: space-evenly;
}
.contactanos-izquierda {
    display: grid;
    align-items: center;
}
button {
    background-color: #9a138b;
    border: 0;
    border-radius: 0.75vw;
    color: white;
}
::placeholder {
    font-size: 1.5vw;
    font-family: carlito;
    color: black;
}
h1 {
    font-size: 3vw;
    align-self: flex-start;
    min-width: 25vh;
    font-family: carlito;
    color: #66139A;
}
textarea {
    min-width: 25vw;
    min-height: 20vh;
    font-size: 1.5vw;
    font-family: carlito;
}
button {
    max-width: 30%;
    align-self: flex-start;
    min-height: 5vh;
    font-size: 1.3vw;
    font-family: carlito;
    color: white;
}
input {
    align-self: flex-start;
    max-width: 70vw;
    min-height: 5vh;
    font-size: 1.2vw;
    font-family: carlito;
    color: black;
}
@media screen and (max-width: 320px) {
    input, button {
        width: 80vw;
        font-size: 4vw;
    }
    textarea {
        width: 70vw;
        min-width: 70vw;
        font-size: 4vw;
    }
    h1 {
        font-size: 10vw;
    }
    ::placeholder {
        font-size: 4vw;
    }
}
@media screen and (max-width: 375px) {
    input, button {
        width: 80vw;
        font-size: 4vw;
    }
    textarea {
        width: 70vw;
        font-size: 4vw;
        min-width: 70vw;
    }
    h1 {
        font-size: 10vw;
    }
    ::placeholder {
        font-size: 4vw;
    }
}
@media screen and (max-width: 425px) {
    input, button {
        width: 80vw;
        font-size: 4vw;
    }
    textarea {
        width: 70vw;
        font-size: 4vw;
        min-width: 70vw;
    }
    h1 {
        font-size: 10vw;
    }
    ::placeholder {
        font-size: 4vw;
    }
}
@media screen and (max-width: 1024px) {
    input, button {
        width: 80vw;
        font-size: 4vw;
    }
    textarea {
        width: 70vw;
        font-size: 4vw;
        min-width: 70vw;
    }
    h1 {
        font-size: 10vw;
    }
    ::placeholder {
        font-size: 4vw;
    }
}
</style>