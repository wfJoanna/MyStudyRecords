// miniprogram/pages/xiugaijine/xiugaijine.js
const db = wx.cloud.database({});
Page({

  /**
   * 页面的初始数据
   */
  data: {
    id: '',
    jine:'',
  },

  inputJine:function(e){
    this.setData({
      jine: e.detail.value
    });
  },

  tijiao:function(e){
    db.collection('order').doc(this.data.id).update({
      data:{
        money: this.data.jine+'元'
      }
    }).then(res =>{
      wx.showToast({
        title : '修改成功',
        icon: 'success',
      })
      setTimeout(function () {
        wx.navigateBack({
          delta: 2
        })
      }, 2000);
    }).catch(err =>{
      wx.showToast({
        title : '修改失败',
        icon: 'none',
      })
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    db.collection('order').doc(options.id).get({
      success: res => {
        // res.data 包含该记录的数据
        this.setData({
          id: options.id,
          order: res.data
        })
      }
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