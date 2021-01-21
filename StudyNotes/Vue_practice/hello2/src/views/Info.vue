<template>
  <div>hello info component<button @click="add()">添加</button></div>
</template>

<script>
import store from '@/store/index.js'
export default {
  name: 'Info',
  store,
  methods: {
    add () {
      console.log('info add')
      store.commit('increase')
    }
  }
}
</script>

<style scoped>
</style>
