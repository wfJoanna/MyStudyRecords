// miniprogram/pages/kefuindex4/kefuindex4.js
var app = getApp();
const db = wx.cloud.database({});


Page({

  /**
   * 页面的初始数据
   */
  data: {
    name:'user',
    src:'/images/user-unlogin.jpg'
  },

  liaotian:function(e){
    db.collection('kefu').where({
      username:this.data.name
    }).get().then(res=>{
      if(res.data[0].state !='咨询中'){
        db.collection('kefu').doc('b887cea95f0682440000025f064901f0').update({
          data:{
            state:'可咨询'
          }
        }).then(res=>{
          wx.navigateTo({
            url: '/pages/kefuindex3/kefuindex3',
          })
        }).catch(err=>{
        })
      }
      else{
        wx.navigateTo({
          url: '/pages/kefuindex3/kefuindex3',
        })
      }
    }).catch({

    });
  },

  sousuo:function(e){
    wx.navigateTo({
      url: '/pages/sousuo/sousuo',
    })
  },

  exit:function(){
    db.collection('kefu').doc('b887cea95f0682440000025f064901f0').update({
      data:{
        state:'已下班'
      }
    }).then(res=>{
      wx.reLaunch({
        url: '/pages/index/index'
      })
    }).catch(err=>{
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    this.setData({
      name: app.globalData.globalName
    })
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})