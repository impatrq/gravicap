import React, { useState, useEffect } from 'react';
import { Bar } from 'react-chartjs-2';
import {
    Chart as ChartJS,
    CategoryScale,
    LinearScale,
    BarElement,
    Title,
    Tooltip,
    Legend,
} from 'chart.js';

// Registro de componentes de Chart.js
ChartJS.register(CategoryScale, LinearScale, BarElement, Title, Tooltip, Legend);

const BarChart = () => {
    // Estado para almacenar los datos del fetch
    const [sensorData, setSensorData] = useState({
        corriente: 0,
        voltage: 0,
        potencia: 0,
    });

    useEffect(() => {
        // Función para obtener datos del servidor
        const fetchData = () => {
            fetch('http://192.168.124.160/sensor?nombre=Sensor_0x44') // IP de la ESP8266 (server)
                .then((response) => response.json())
                .then((data) => {
                    setSensorData({
                        corriente: data.corriente,
                        voltage: data.voltage,
                        potencia: data.potencia,
                    });
                    console.log('Datos actualizados:', data); // Verificar los valores
                })
                .catch((error) => {
                    console.error('Error al obtener los datos:', error);
                });
        };
        // Llamamos a fetchData al montar el componente
        fetchData();
        // Configuramos el intervalo para actualizar los datos cada 2 segundos
        const interval = setInterval(fetchData, 2000);
        // Limpiamos el intervalo al desmontar el componente
        return () => clearInterval(interval);
    }, []);
    // Datos dinámicos del gráfico
    const data = {
        labels: ['Voltaje', 'Amperaje', 'Wataje'],
        datasets: [
            {
                label: 'Valores',
                data: [
                    sensorData.voltage, // Voltaje dinámico
                    sensorData.corriente, // Corriente dinámica
                    sensorData.potencia, // Potencia dinámica
                ],
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                borderColor: 'rgba(75, 192, 192, 1)',
                borderWidth: 1,
            },
        ],
    };

    // Opciones del gráfico
    const options = {
        responsive: true,
        plugins: {
            legend: {
                position: 'top',
            },
        },
    };

    return <Bar data={data} options={options} />;
};

export default BarChart;
