<template>
<div>
  <router-view />
  <ul class="footer">
      <li><router-link :to="{name: 'list'}">新闻列表</router-link></li>
      <li><router-link :to="{name: 'user'}">个人中心</router-link></li>
  </ul>
</div>
</template>

<script>
export default {
  name: 'Home'
}
</script>

<style scoped>
.footer{
  position: fixed;
  width: 100%;
  height: 60px;
  line-height: 60px;
  left: 0;
  bottom: 0;
  display: flex;
  flex-flow: row nowrap;
  justify-content: space-around;
}
</style>
