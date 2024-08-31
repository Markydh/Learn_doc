import { createApp } from 'vue'
import router from "@/router/index.js"
import App from './App.vue'
import "./css/tailwindcss.css"
//svg图标的设置
import '@/assets/icon'
import svgIcon from '@/assets/icon/Svg.vue'

createApp(App)
    .component('svg-icon',svgIcon)
    .use(router)
    .mount('#app')