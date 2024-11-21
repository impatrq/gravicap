// LineChart.jsx
import React from 'react';
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

// Registro de componentes de Chart.js
ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend);

const LineChart1 = () => {
    // Datos del gráfico
    const data = {
        labels: ['0', '1', '2', '3', '4', '5'],
        datasets: [
            {
                label: 'Potencia',
                data: [150, 100, 70, 50, 20, 0],
                fill: false,
                borderColor: 'rgba(75, 192, 192, 1)',
                tension: 0.1, // Suavidad de la línea
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
            title: {
                display: true,
                text: 'Gráfico de Potencia de Descarga',
            },
        },
    };

    return <Line data={data} options={options} />;
};

export default LineChart1;