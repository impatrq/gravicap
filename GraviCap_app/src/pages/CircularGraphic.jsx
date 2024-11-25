import React from 'react';
import { Doughnut } from 'react-chartjs-2';
import {
  Chart as ChartJS,
  ArcElement,
  Tooltip,
  Legend,
} from 'chart.js';

// Registro de componentes de Chart.js
ChartJS.register(ArcElement, Tooltip, Legend);

const CircularChart = ({ value }) => {
  const minValue = 0;
  const maxValue = 5;

  // Datos del gráfico
  const data = {
    labels: ['Energía Generada', 'Espacio Restante'],
    datasets: [
      {
        label: 'Gráfico Circular',
        data: [value, maxValue - value],
        backgroundColor: [
          'rgba(129, 14, 200, 0.6)', // Color para el valor
          'rgba(255, 206, 86, 0.5)', // Color para el espacio restante
        ],
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
  return <Doughnut data={data} options={options} />;
};

export default CircularChart;
