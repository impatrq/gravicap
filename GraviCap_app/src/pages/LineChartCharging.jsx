import React, { useState, useEffect } from 'react';
import { Line } from 'react-chartjs-2';
import {
    Chart as ChartJS,
    CategoryScale,
    LinearScale,
    PointElement,
    LineElement,
    Title,
    Tooltip,
    Legend,
} from 'chart.js';

ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend);

const LineChart = () => {
    const [chartData, setChartData] = useState({
        labels: [],
        datasets: [
            {
                label: 'Potencia',
                data: [],
                fill: false,
                borderColor: 'rgba(75, 192, 192, 1)',
                tension: 0.1,
            },
        ],
    });

    const [recording, setRecording] = useState(false); // Estado para controlar si estamos grabando
    const maxPotencia = 100; // Valor máximo de potencia para detener el gráfico

    const fetchData = async () => {
        try {
            const response = await fetch('http://<192.168.124.160>/sensor?nombre=Sensor_0x44');
            if (!response.ok) {
                throw new Error('Error en la solicitud');
            }

            const data = await response.json();
            const { potencia } = data;
            const timestamp = new Date().toLocaleTimeString();

            if (!recording && potencia === 0) {
                // Inicia la grabación si la potencia es 0
                setRecording(true);
            }

            if (recording) {
                // Actualiza el gráfico solo si estamos grabando
                setChartData((prevData) => ({
                    labels: [...prevData.labels, timestamp],
                    datasets: [
                        {
                            ...prevData.datasets[0],
                            data: [...prevData.datasets[0].data, potencia],
                        },
                    ],
                }));

                // Detén la grabación si se alcanza la potencia máxima
                if (potencia >= maxPotencia) {
                    setRecording(false);
                    console.log('Detenido: Se alcanzó la potencia máxima');
                }
            }
        } catch (error) {
            console.error('Error al obtener datos:', error);
        }
    };

    useEffect(() => {
        const interval = setInterval(() => {
            fetchData();
        }, 2000);

        return () => clearInterval(interval); // Limpia el intervalo al desmontar
    }, [recording]); // Solo reinicia el efecto si cambia `recording`

    const options = {
        responsive: true,
        plugins: {
            legend: {
                position: 'top',
            },
            title: {
                display: true,
                text: 'Gráfico de Potencia de Carga',
            },
        },
    };

    return <Line data={chartData} options={options} />;
};

export default LineChart;
