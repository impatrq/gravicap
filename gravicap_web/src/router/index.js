import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import GaleriaView from '../views/GaleriaView.vue'
import NosotrosView from '../views/NosotrosView.vue'
import ContactanosView from '../views/ContactanosView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/home',
      name: 'home',
      component: HomeView
    },
    {
      path: '/',
      redirect: '/home',
      component: HomeView
    },
    {
      path: '/sobre_nosotros',
      name: 'sobre_nosotros',
      redirect: '/sobre_nosotros',
      component: () => import('../views/NosotrosView.vue')
    },
    {
      path: '/galeria',
      name: 'galeria',
      redirect: '/galeria',
      component: () => import('../views/GaleriaView.vue')
    },
    {
      path: '/contactanos',
      name: 'contactanos',
      redirect: '/contactanos',
      component: () => import('../views/ContactanosView.vue')
    }
  ]
})

export default router
