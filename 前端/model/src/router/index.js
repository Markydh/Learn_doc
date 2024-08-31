import { createMemoryHistory, createRouter } from 'vue-router'

import login from "@/View/login";
import register from "@/View/register";
import index from "@/View/index"


const routes = [
    {path:'/',component: index},
    {path:'/login',component:login},
    {path: 'register',component:register}
]

const router = createRouter({
    history: createMemoryHistory(),
    routes,
})

export default router