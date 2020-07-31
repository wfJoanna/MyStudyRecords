// miniprogram/pages/zhifu/zhifu.js
const db = wx.cloud.database({});

Page({

  /**
   * 页面的初始数据
   */
  data: {
    id:'',
  },

  yizhifu:function(e){
    db.collection('order').doc(this.data.id).update({
      data:{
        ddzt:'等待客户评价',
        status:'已完成'
      }
    }).then(res=>{
      wx.showToast({
        title:'支付成功',
        icon:'success',
      });
      setTimeout(function () {
        wx.navigateBack({
          delta: 2
        })
      }, 2000);
    }).catch(err=>{
      wx.showToast({
        title:'支付失败',
        icon:'none'
      }) 
    })
  },

  weizhifu:function(e){
    wx.showToast({
      title:'支付失败',
      icon:'none'
    }) ;
    setTimeout(function () {
      wx.navigateBack({
        delta: 2
      })
    }, 2000);
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.setData({
      id:options.id
    })
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