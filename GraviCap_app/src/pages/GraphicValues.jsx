// BarChart.jsx
import React from 'react';
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
    // Datos del gráfico
    const data = {
        labels: ['Voltaje', 'Amperaje', 'Wataje'],
        datasets: [
            {
                label: 'Valores',
                data: [24, 5, 15,],
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
            title: {
                display: true,
                text: 'Valores de Batería',
            },
        },
    };

    return <Bar data={data} options={options} />;
};

export default BarChart;
